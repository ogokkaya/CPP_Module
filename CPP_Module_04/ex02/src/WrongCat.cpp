#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "\033[32mDefault constructor for WrongCat called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "\033[32mCopy constructor for WrongCat called\033[0m" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "\033[32mAssignation operator for WrongCat called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.getType();
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "\033[32mDeconstructor for WrongCat called\033[0m" << std::endl;
}

void WrongCat::makeSound(void)const
{
    std::cout << this->getType() << " : Miyavv" << std::endl;
}
