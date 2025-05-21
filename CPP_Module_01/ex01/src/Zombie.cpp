#include "../include/Zombie.hpp"


Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << "\033[34m" <<this->_name << ": \033[33mdestroyed\033[0m" << std::endl;
}

void Zombie::announce(void)const
{
    std::cout << "\033[34m" <<this->_name << ": " << "\033[31mBraiiiiiiinnnzzzZ...\033[0m\n" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}