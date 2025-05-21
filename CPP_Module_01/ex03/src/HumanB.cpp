#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->is_armed = false;
}

HumanB::~HumanB(void)
{
    std::cout << "\033[32m" <<this->name << " died\033[0m" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
    this->is_armed = true;
    std::cout << "\033[33m" << this->name << " grabbed a" << this->weapon->getType() << "to fight with\033[0m" << std::endl;
}

void HumanB::attack(void)
{
    if(this->is_armed)
        std::cout << "\033[33m" <<this->name << " attacks with his" << this->weapon->getType() << "\033[0m" << std::endl;
    else
         std::cout << this->name << "attacks with his fists" << std::endl;
}