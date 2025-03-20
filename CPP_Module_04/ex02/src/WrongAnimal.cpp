#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "\033[32mDefault constructor for WrongAnimal called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "\033[32mCopy constructor for WrongAnimal called\033[0m" << std::endl; 
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "\033[32mAssignation operator for WrongAnimal called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.getType();
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[32mDeconstructor for WrongAnimal called\033[0m" << std::endl;
}

void WrongAnimal::makeSound(void)const
{
    std::cout << "The Wronganimal doesn't make any sound." << std::endl;
}

std::string const &WrongAnimal::getType(void)const
{
    return(this->type);
}

void WrongAnimal::setType(std::string type)
{
    this->type = type;
}
