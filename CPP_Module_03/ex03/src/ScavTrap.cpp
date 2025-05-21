#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
    this->HitPoint = 100;
    this->EnergyPoint = 50;
    this->AttackDamage = 20;
    this->guardMode = false;
    std::cout << "\033[32mScavTrap Constructor for name " << this->name << " called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->HitPoint = 100;
    this->EnergyPoint = 50;
    this->AttackDamage = 20;
    this->guardMode = false;
    std::cout << "\033[32mScavTrap Constructor for the name " << this->name << " called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    *this = copy;
    std::cout << "\033[32mScavTrap Copy Constructor called\033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "\033[32mScavTrap Assignation operator called\033[0m" << std::endl;
    if(this != &copy)
    {
        this->name = copy.getName();
        this->HitPoint = copy.getHitPoints();
        this->EnergyPoint = copy.getEnergyPoints();
        this->AttackDamage = copy.getAttackDamage();
        this->guardMode= copy.guardMode;
    }
    return(*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[32mScavTrap Deconstructor for " << name << " called\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if(this->HitPoint > 0 && this->EnergyPoint > 0)
    {
        if (this->guardMode == true)
            this->guardMode = false;
        std::cout << "ScavTrap " << this->name
                  << "attacks " << target
                  << ", causing " << this->AttackDamage
                  << " points of damage!" << std::endl;
        this->EnergyPoint--;
        std::cout << "Energy points remaining: " << this->EnergyPoint << std::endl; 
    }
    else if (this->EnergyPoint == 0)
    {
        std::cout << "\033[31mScavTrap " << this->name
                  << " cannot attack " << target
                  << " because it has no energy points  left\033[0m" << std::endl;
    }
    else
        std::cout << "\033[31mScavTrap " << this->name
                  << " cannot attack " << target
                  << " because it has no hit points left\033[0m" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if(this->HitPoint > 0 && this->EnergyPoint > 0 && this->guardMode == false)
    {
        this->guardMode = true;
        std::cout << "ScavTrap " << this->name << " has entered Gatekeeper mode!" << std::endl;
    }
    else if (this->HitPoint == 0)
    {
        std::cout << "ScavTrap " << this->name << " cannot enter Gatekeeper mode because it has no hit points left.\033[0m" << std::endl;
    }
    else if (this->EnergyPoint == 0)
    {
        std::cout << "ScavTrap " << this->name << " cannot enter Gatekeeper mode because it has no energy points left.\033[0m" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " is already guarding the gate" << std::endl;
}