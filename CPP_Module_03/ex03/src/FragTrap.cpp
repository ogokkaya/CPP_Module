#include "../include/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    this->HitPoint = 100;
    this->EnergyPoint = 100;
    this->AttackDamage = 30;
    std::cout << "\033[32mFragTrap Constructor for name " << this->name << " called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->HitPoint = 100;
    this->EnergyPoint = 100;
    this->AttackDamage = 30;
    std::cout << "\033[32mFragTrap Constructor for name " << this->name << " called\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    *this = copy;
    std::cout << "\033[32mFragTrap Copy Constructor called\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "\033[32mFragTrap Assignation operator called\033[0m" << std::endl;
    if(this != &copy)
    {
        this->name = copy.getName();
        this->HitPoint = copy.getHitPoints();
        this->EnergyPoint = copy.getEnergyPoints();
        this->AttackDamage = copy.getAttackDamage();
    }
    return(*this);
}

FragTrap::~FragTrap()
{
    std::cout << "\033[32mFragTrap Deconstructor for " << name << " called\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if(this->HitPoint > 0)
        std::cout << "FragTrap " << this->name << " wants a high-five!" << std::endl;
    else
        std::cout << "FragTrap " << this->name << " is dead and can't high-five" << std::endl;

}