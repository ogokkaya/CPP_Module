#pragma once

#include <iostream>

class Weapon
{
    private:
        std::string  _type;
    public:
        Weapon(const std::string &Weapon);
        ~Weapon();
    void setType(const std::string &Weapon);
    std::string getType(void)const;
};