#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "\033[32mDefault constructor for Cat called\033[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "\033[32mCopy constructor for Cat called\033[0m" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "\033[32mAssignation operator for Cat called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "\033[32mDeconstructor for Cat called\033[0m" << std::endl;
}

void Cat::makeSound(void)const
{
    std::cout << this->getType() << " : Miyavv" << std::endl;
}
