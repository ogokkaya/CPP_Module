#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cctype>

Date::Date() : _year(0), _month(0), _day(0) {}

Date::Date(const Date &other) { *this = other; }

Date &Date::operator=(const Date &other) {
    if (this != &other) {
        _year = other._year;
        _month = other._month;
        _day = other._day;
    }
    return (*this);
}

Date::~Date() {}

Date::Date(const std::string &dateStr) {
    std::stringstream ss(dateStr);
    char d1, d2;

    if (!((ss >> _year >> d1 >> _month >> d2 >> _day) && d1 == '-' && d2 == '-')) {
        _year = 0; _month = 0; _day = 0;
    }

}

bool Date::operator<(const Date &other) const {
    if (_year != other._year) return (_year < other._year);
    if (_month != other._month) return (_month < other._month);
    return (_day < other._day);
}

bool Date::operator>(const Date &other) const { return other < *this; }

bool Date::operator==(const Date &other) const {
    return (_year == other._year && _month == other._month && _day == other._day);
}

bool Date::isValid() const {
    if (_year < 0 || _month < 1 || _month > 12 || _day < 1 || _day > 31) return false;

    if (_month == 2) {
        bool isLeap = (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
        if (isLeap && _day > 29) return false;
        if (!isLeap && _day > 28) return false;
    }
    

    if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day > 30) {
        return false;
    }
    return true;
}

int Date::getYear() const { return _year; }
int Date::getMonth() const { return _month; }
int Date::getDay() const { return _day; }

static int my_isspace(int c) {
    return std::isspace(c);
}

static std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(my_isspace))));
    return s;
}

static std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(my_isspace))).base(), s.end());
    return s;
}

static std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _data = other._data;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        if (line.empty()){
            continue;
        }
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) continue;
        
        std::string rawDate = line.substr(0, commaPos);
        std::string rawRate = line.substr(commaPos + 1);
        
        trim(rawDate);
        trim(rawRate);
        
        try {

            Date date(rawDate); 
            if (!date.isValid()){
                continue; 
            }
            float rate = safeStof(rawRate);
            _data[date] = rate;
        }
        catch (const std::exception &e){
            continue;
        }
    }
    file.close();

    if (_data.empty()){
        throw std::runtime_error("Error: database file is empty or invalid.");
    }
}

float BitcoinExchange::safeStof(const std::string &str) {
    if (str.empty()){
        throw std::invalid_argument("Empty string");
    } 
    
    char* endPtr;
    double val = std::strtod(str.c_str(), &endPtr);
    
    if (str.c_str() == endPtr){
        throw std::invalid_argument("Not a number");
    }
    if (*endPtr != '\0'){
        throw std::invalid_argument("Invalid characters in number");
    }
    return static_cast<float>(val);
}

void BitcoinExchange::run(const std::string &fileName){
    
    std::ifstream file(fileName.c_str());
    if (!file.is_open()){
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value" && line != "date|value"){
        throw std::runtime_error("Error : hatalı dosya başlangıcı");
    }

    while (std::getline(file, line)) {
        if (line.empty()){
            continue;
        }

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string rawDate = line.substr(0, pipePos);
        std::string rawValue = line.substr(pipePos + 1);

        trim(rawDate);
        trim(rawValue);


        Date date(rawDate); 
        
        if (!date.isValid()) {
            std::cout << "Error: bad input => " << rawDate << std::endl;
            continue;
        }

        float value;
        try {
            value = safeStof(rawValue);
        }
        catch (std::exception &e){
            std::cout << "Error: bad input => " << rawValue << std::endl;
            continue;
        }

        if (value < 0){
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000){
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

    
        std::map<Date, float>::iterator it = _data.lower_bound(date);

        if (it == _data.begin() && !(it->first == date)){
             std::cout << "Error: date too old => " << rawDate << std::endl;
             continue;
        }
        
        if (it == _data.end() || !(it->first == date)){
            it--;
        }

        float result = value * it->second;
        std::cout << rawDate << " => " << value << " = " << result << std::endl;
    }
    file.close();
}