#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool guardMode;
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);
        ~ScavTrap();
    
        void attack(const std::string &target);
        void guardGate(void);
};