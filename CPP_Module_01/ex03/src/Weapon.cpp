#include "../include/Weapon.hpp"

Weapon::Weapon(const std::string &Weapon)
{
    this->_type = Weapon;
}

Weapon::~Weapon()
{
    std::cout << "\033[32m"<< this->getType() << " dropped to the floor and broke\033[0m" << std::endl;
}


std::string Weapon::getType(void)const
{
    return(this->_type);
}

void Weapon::setType(const std::string &Weapon)
{
    this->_type = Weapon;
}

