#pragma once 

#include <iostream>

class Zombie
{
    private:
    std::string _name;

    public:
    Zombie(std::string name);
    ~Zombie();

    void annonce()const;
};

Zombie *newZombie(std::string   name);
void randomChump(std::string name);