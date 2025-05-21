#pragma once

#include <iostream>

class Fixed
{
    private:
        int FixedPointNum;
        static const int FractBitsNum = 8;
    public:
        Fixed(void);
        Fixed(int Num);
        Fixed(const float Num);
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed &copy);
        ~Fixed();
    void setRawBits(int const raw);
    int getRawBits(void)const;
    float toFloat(void)const;
    int toInt(void)const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);