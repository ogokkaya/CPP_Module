#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>


class Date {
private:
    int _year;
    int _month;
    int _day;

public:
    Date();
    Date(const std::string &dateStr);
    Date(const Date &other);
    Date &operator=(const Date &other);
    ~Date();

    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator==(const Date &other) const;

    bool isValid() const;

    int getYear() const;
    int getMonth() const;
    int getDay() const;
};


class BitcoinExchange {
private:
    std::map<Date, float> _data; 
    float safeStof(const std::string& str);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void run(const std::string &fileName);
};

#endif