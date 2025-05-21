#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("default"), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "\033[32mClapTrap Default Constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :name(name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
    std::cout << "\033[32mClapTrap Constructor for the name " << this->name << " called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "\033[32mClapTrap Copy Constructor called\033[0m" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "\033[32mClapTrap Assignation operator called\033[0m" << std::endl;
    if(this != &copy)
    {
        this->name = copy.name;
        this->HitPoint = copy.HitPoint;
        this->EnergyPoint = copy.EnergyPoint;
        this->AttackDamage = copy.AttackDamage;
    }
    return(*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[32mClapTrap Deconstructor for " << name << " called\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->HitPoint > 0 && this->EnergyPoint > 0)
    {
        std::cout << "ClapTrap " << this->name 
                  << " attacks " << target 
                  << ", causing " << this->AttackDamage 
                  << " points of damage!" << std::endl;
        this->EnergyPoint--;
        std::cout << "Energy points remaining: " << this->EnergyPoint << std::endl;
    }
    else if (this->EnergyPoint == 0)
    {
        std::cout << "\033[31mClapTrap " << this->name 
                  << " cannot attack " << target 
                  << " because it has no energy points left\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[31mClapTrap " << this->name 
                  << " cannot attack " << target 
                  << " because it has no hit points left\033[0m" << std::endl;
    }
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoint > amount)
    {
        this->HitPoint -= amount;
        std::cout << "ClapTrap " << this->name 
                  << " was attacked and lost " << amount 
                  << " hit points. Current hit points: " 
                  << this->HitPoint << std::endl;
    }
    else if (this->HitPoint > 0)
    {
        this->HitPoint = 0;
        std::cout << "\033[31mClapTrap " << this->name 
                  << " was attacked and lost all its hit points! It is now dead\033[0m" 
                  << std::endl;
    }
    else
    {
        std::cout << "\033[33mClapTrap " << this->name 
                  << " is already dead. Stop attacking!\033[0m" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->HitPoint > 0 && this->EnergyPoint > 0 && this->HitPoint + amount <= 10)
    {
        this->EnergyPoint--;
        this->HitPoint += amount;
        std::cout << "ClapTrap " << this->name << " repaired itself and gained " 
                  << amount << " hit points. Current hit points: " << this->HitPoint
                  << ", energy points: " << this->EnergyPoint << std::endl;
    }
    else if (this->EnergyPoint == 0)
        std::cout << "\033[31mClapTrap " << this->name 
                  << " cannot repair itself due to insufficient energy points\033[0m" 
                  << std::endl;
    else if (this->HitPoint == 0)
        std::cout << "\033[31mClapTrap " << this->name 
                  << " cannot repair itself because it has no hit points left\033[0m" 
                  << std::endl;
    else
        std::cout << "\033[33mClapTrap " << this->name 
                  << " cannot exceed the maximum limit of 10 hit points\033[0m" 
                  << std::endl;
}

std::string ClapTrap::getName(void)const
{
    return(this->name);
}

unsigned int ClapTrap::getHitPoints(void)const
{
    return(this->HitPoint);
}

unsigned int ClapTrap::getEnergyPoints(void)const
{
    return(this->EnergyPoint);
}

unsigned int ClapTrap::getAttackDamage(void)const
{
    return(this->AttackDamage);
}

