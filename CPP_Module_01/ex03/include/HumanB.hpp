#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
        bool is_armed;
    public:
        HumanB(std::string name);
        ~HumanB();
    void setWeapon(Weapon &weapon);
    void attack(void);
};