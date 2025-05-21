#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("defaultDiamodTClapTrap")
{
    this->name = "defaultDT";
    this->HitPoint = 100;
    this->EnergyPoint = 50;    
    this->AttackDamage = 30;
    std::cout << "\033[32mDiamondTrap Default Constructor called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
    this->name = name;
    this->HitPoint = 100;
    this->EnergyPoint = 50;
    this->AttackDamage = 30;
    std::cout << "\033[32mDiamondTrap Constructor for name " << this->name << " called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    std::cout << "\033[32mDiamondTrap Copy Constructor called\033[0m" << std::endl;
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "\033[32mDiamondTrap Assignation operator called\033[0m" << std::endl;
    if(this != &copy)
    {
        this->name = copy.name;
        ClapTrap::operator=(copy);
    }
    return(*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[32mDiamondTrap Deconstructor for " << name << " called\033[0m" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << this->name
              << "\nClapTrap name: " << ClapTrap::name
              << std::endl;
}