#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "\033[32mDefault constructor for Dog called\033[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "\033[32mCopy constructor for Dog called\033[0m" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "\033[32mAssignation operator for Dog called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "\033[32mDeconstructor for Dog called\033[0m" << std::endl;
}

void Dog::makeSound(void)const
{
    std::cout << this->getType() << " : HavHav" << std::endl;
}