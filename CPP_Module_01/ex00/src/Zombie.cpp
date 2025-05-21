#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "\033[31m" << this->_name << ":\033[34m creadted" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "\033[31m" << _name << ":\033[33m died\033[0m"  << std::endl;
}

void Zombie::annonce(void)const
{
    std::cout << "\033[31m" << this->_name << ": Braiiiiiiinnnzzz...\033[33m\n" << std::endl;
}