#include "../include/Zombie.hpp"

int main()
{
    int zombieCount = 11;
    Zombie *horde = zombieHorde(zombieCount, "Zombie");
    if(horde == NULL)
        return(1);
    else
    {
        for(int i = 0; i < zombieCount; i++)
            horde[i].announce();
        delete[] horde;
    }
    return(0);
}
