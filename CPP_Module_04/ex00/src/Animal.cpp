#include "../include/Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "\033[32mDefault constructor for Animal called\033[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "\033[32mCopy constructor for Animal called\033[0m" << std::endl; 
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "\033[32mAssignation operator for Animal called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "\033[32mDeconstructor for Animal called\033[0m" << std::endl;
}

void Animal::makeSound(void)const
{
    std::cout << "The animal doesn't make any sound." << std::endl;
}

std::string const &Animal::getType(void)const
{
    return(this->type);
}

void Animal::setType(std::string type)
{
    this->type = type;
}
