#pragma once 

#include <iostream>


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();
        
        enum {INT , CHAR , FLOAT, DOUBLE };
        const std::string _input;
        
        int type;
        int _int;
        char _char;
        float _float;
        double _double;
        int pointCount;

        bool limI;
        bool limC;
        bool limF;
        bool limD;

        void handlePseudoLiteral(const std::string &input);

        void isChar(const int &c);
        void isInt(long double v);
        void isFloat(long double v);
        void isDouble(long double v);
        void digitType(const std::string &input);
        void displayChar()const;
        void displayInt()const;
        void displayDouble()const;
        void displayFloat()const;
        void displayConverter(void)const;
        void determendType(const std::string &input);

    public:
        static void convert(const std::string &literal);
    };