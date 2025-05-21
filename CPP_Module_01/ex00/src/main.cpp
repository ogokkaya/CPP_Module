#include "../include/Zombie.hpp"

int main()
{
    Zombie *walkingDead = newZombie("Boss Zombie  ");
    randomChump("Basic Zombie ");
    delete(walkingDead);
    return(0);
}