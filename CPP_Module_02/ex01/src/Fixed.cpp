#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : FixedPointNum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int Num)
{
    std::cout << "Int Constructor Called" << std::endl;
    this->FixedPointNum = Num << this->FractBitsNum;
}
Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;
}
Fixed::Fixed(const float Num)
{
    std::cout << "Float Constructor Called" << std::endl;
    this->FixedPointNum = roundf(Num * (1 << this->FractBitsNum));
}

float Fixed::toFloat(void)const
{
    return((float)(this->FixedPointNum) / (float)(1 << this->FractBitsNum));
}

int Fixed::toInt(void)const
{
    return(this->FixedPointNum >> this->FractBitsNum);
}

void Fixed::setRawBits(int const raw)
{
    this->FixedPointNum = raw;
}
int Fixed::getRawBits(void)const
{
    return(this->FixedPointNum);
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if(this != &copy)
        this->FixedPointNum = copy.getRawBits();
    return(*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return(out);
}
