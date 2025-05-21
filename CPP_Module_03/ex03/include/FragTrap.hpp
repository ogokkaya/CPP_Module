#pragma once

#include "../include/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
        ~FragTrap();
    
        void highFivesGuys(void);
};