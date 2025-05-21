#include "../include/Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *walkingDead = new Zombie(name);
    walkingDead->annonce();
    return(walkingDead);
}