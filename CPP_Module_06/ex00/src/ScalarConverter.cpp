#include "../include/ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() : pointCount(1), limI(false), limC(false), limF(false), limD(false) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {*this = copy;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return (*this);
}

ScalarConverter::~ScalarConverter(){}


void ScalarConverter::isChar(const int &c)
{
    if((c < 0 || c > 127) || !isascii(c))
        this->limC = true;
    if (this->type == this->INT)
        this->_char = static_cast<char>(c);
    else
    {
        this->_char = static_cast<char>(c);
        this->_int = static_cast<int>(c);
        this->_float = static_cast<float>(c);
        this->_double = static_cast<double>(c);
        this->type = this->CHAR;
    }
}

void ScalarConverter::isInt(long double v)
{
    if ((v != 0.0 && std::fabs(v) < 1.0) || (v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max()))
    {
        this->limI = true;
        this->limC = true;
    }
    else
    {
        this->type = this->INT;
        this->isChar(static_cast<int>(v));
        this->_int = static_cast<int>(v);
        this->_float = static_cast<float>(v);
        this->_double = static_cast<double>(v);
    }
}

void ScalarConverter::isFloat(long double v)
{
    if (std::fabs(v) > std::numeric_limits<float>::max() || (v != 0.0 && std::fabs(v) < std::numeric_limits<float>::min()))
        this->limF = true;
    else
    {
        this->_float = static_cast<float>(v);
        this->_double = static_cast<double>(v);
        this->type = this->FLOAT;
    }
}

void ScalarConverter::isDouble(long double v)
{
    if (std::fabs(v) > std::numeric_limits<double>::max() || (v != 0.0 && std::fabs(v) < std::numeric_limits<double>::min()))
        this->limD = true;
    else
    {
        this->_double = static_cast<double>(v);
        this->type = this->DOUBLE;
    }
}

void ScalarConverter::digitType(const std::string &input)
{
    char *end = NULL;

    long double value = std::strtod(input.c_str(), &end);

    std::size_t dot = input.find('.');
    if (dot != std::string::npos)
    {
        std::string fractional = input.substr(dot + 1);
    
        int count = 0;
        for (std::size_t i = 0; i < fractional.length(); ++i)
            {
            if (std::isdigit(fractional[i]))
                ++count;
            }
        pointCount = count;
    }
    else
        pointCount = 1;
    while (std::isspace(*end)) ++end;

    if (*end != '\0' && !((*end == 'f' && *(end+1) == '\0')))
    {
        limC = limI = limF = limD = true;
        return;
    }
    isInt(value);
    if (this->type != this->INT)
    {
        isFloat(value);
        if (this->type != this->FLOAT)
            isDouble(value);
    }
}

void ScalarConverter::handlePseudoLiteral(const std::string &input)
{
    if (input == "nan" || input == "nanf")
    {
        this->_double = std::numeric_limits<double>::quiet_NaN();
        this->_float = std::numeric_limits<float>::quiet_NaN();
    }
    else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        this->_double = std::numeric_limits<double>::infinity();
        this->_float = std::numeric_limits<float>::infinity();
    }
    else if (input == "-inf" || input == "-inff")
    {
        this->_double = -std::numeric_limits<double>::infinity();
        this->_float = -std::numeric_limits<float>::infinity();
    }
    else
    {
        this->limF = true;
        this->limD = true;
    }
}

void ScalarConverter::displayChar() const
{
    if (this->limC)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(this->_char))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << this->_char << "'" << std::endl;
}

void ScalarConverter::displayInt()const
{
    if (this->limI)
        std::cout << "Int: impossible " << std::endl;
    else
        std::cout << "int: " << this->_int << std::endl;
}

void ScalarConverter::displayFloat()const
{
    if (this->limF)
        std::cout << "Float: impossible " << std::endl;
    else
    {
        if (std::fabs(this->_float) > 1e6f || (std::fabs(this->_float) < 1e-4f && this->_float != 0.0f))
            std::cout << std::scientific;
        else
            std::cout << std::fixed;
        std::cout << std::setprecision(pointCount) << "float: " << this->_float << "f" << std::endl;
    }
}

void ScalarConverter::displayDouble()const
{
    if (this->limD)
        std::cout << "Double: impossible " << std::endl;
    else
    {
        if (std::fabs(this->_double) > 1e6 || (std::fabs(this->_double) < 1e-4 && this->_double != 0.0))
            std::cout << std::scientific;
        else
            std::cout << std::fixed;
        std::cout << std::setprecision(pointCount) << "double: " << this->_double << std::endl;
    }
}

void ScalarConverter::displayConverter()const
{
    displayChar();
    displayInt();   
    displayFloat();
    displayDouble();
}

void ScalarConverter::determendType(const std::string &input)
{
    if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
        isChar(input[0]);
    else if ((input[0] == '+' && isdigit(input[1])) || (input[0] == '-' && isdigit(input[1])) || isdigit(input[0]))
        digitType(input);
    else
    {
        this->limC = true;
        this->limI = true;
        handlePseudoLiteral(input);
    }
    displayConverter();
}

void ScalarConverter::convert(const std::string &literal)
{
    ScalarConverter data;

    data.determendType(literal);
}