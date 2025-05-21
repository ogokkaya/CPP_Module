#pragma once

#include <iostream>

class Fixed
{
    private:
        int FixedPointNum;
        static const int FractBitsNum = 8;
    public:
        Fixed(void);
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed &operator=(const Fixed &copy);

    void setRawBits(int const raw);
    int getRawBits(void)const;
};
