#pragma once

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        unsigned int HitPoint;
        unsigned int EnergyPoint;
        unsigned int AttackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
        std::string getName(void)const;
        unsigned int getHitPoints(void)const;
        unsigned int getEnergyPoints(void)const;
        unsigned int getAttackDamage(void)const;
};