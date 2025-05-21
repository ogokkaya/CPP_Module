#pragma once

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
        ~FragTrap();
    
        void highFivesGuys(void);
};