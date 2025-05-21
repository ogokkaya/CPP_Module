#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : FixedPointNum(0)
{
}

Fixed::Fixed(const int input)
{
    this->FixedPointNum = input << this->FractBitsNum;
}

Fixed::Fixed(const float input)
{
    this->FixedPointNum = roundf(input * (1 << this->FractBitsNum));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void)const
{
    return(this->FixedPointNum);
}

void Fixed::setRawBits(const int raw)
{
    this->FixedPointNum = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if(this != &copy)
        this->FixedPointNum = copy.getRawBits();
    return(*this);
}

float Fixed::toFloat(void)const
{
    return ((float)(this->FixedPointNum) / (float)(1 << this->FractBitsNum));
}

int Fixed::toInt(void)const
{
    return(this->FixedPointNum >> this->FractBitsNum);
}

bool  Fixed::operator==(Fixed fixed)const
{
    return(this->toFloat() == fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed)const
{
    return(this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed)const
{
    return(this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed)const
{
    return(this->toFloat() != fixed.toFloat());
}

bool Fixed::operator>(Fixed fixed)const
{
    return(this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed)const
{
    return(this->toFloat() < fixed.toFloat());
}

float Fixed::operator+(Fixed fixed)const
{
    return(this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed)const
{
    return(this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed)const
{
    return(this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed fixed)const
{
    return(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
    this->FixedPointNum += 1;
    return (*this);
}

Fixed Fixed::operator--()
{
    this->FixedPointNum -= 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->FixedPointNum += 1;
    return(temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->FixedPointNum -= 1;
    return(*this);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
    if(first.toFloat() >= second.toFloat())
        return(first);
    return(second);
}
Fixed &Fixed::min(Fixed &first, Fixed &second)
{
    if(first.toFloat() <= second.toFloat())
        return(first);
    return(second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
    if(first.toFloat() >= second.toFloat())
        return(first);
    return(second);
}
const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
    if(first.toFloat() <= second.toFloat())
        return(first);
    return(second);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return(out);
}