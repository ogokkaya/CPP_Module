#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): weapon(weapon)
{
    this->name = name;
    std::cout << "\033[33m" << this->name << " joined the battlefield and grabbed a "<< this->weapon.getType() << "to figth\033[0m" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "\033[32m" << this->name << " died\033[0m" << std::endl;
}

void HumanA::attack(void)const
{
    std::cout << "\033[33m" << this->name << " attacks with his" << this->weapon.getType() << "\033[0m" << std::endl; 
}