#pragma once

#include <iostream>

class Fixed
{
    private:
        int FixedPointNum;
        static const int FractBitsNum = 8;
    public:
        Fixed(void);
        Fixed(const int input);
        Fixed(const float input);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();
        
        float toFloat(void)const;
        int toInt(void)const;

        bool operator==(Fixed fixed)const;
        bool operator>=(Fixed fixed)const;
        bool operator<=(Fixed fixed)const;
        bool operator!=(Fixed fixed)const;
        bool operator>(Fixed fixed)const;
        bool operator<(Fixed fixed)const;

        float operator+(Fixed fixed)const;
        float operator-(Fixed fixed)const;
        float operator*(Fixed fixed)const;
        float operator/(Fixed fixed)const;
    
        Fixed operator--();
        Fixed operator++();
    
        Fixed operator++(int);
        Fixed operator--(int);
    
        static Fixed &max(Fixed &a , Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);

        static const Fixed &max(const Fixed &first, const Fixed &second);
        static const Fixed &min(const Fixed &first, const Fixed &second);

    int getRawBits(void)const;
    void setRawBits(const int raw);
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);