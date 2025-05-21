#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if(N < 1)
    {
        std::cout << "\033[31mA Horde can not contain less than 1 Zombie\033[0m" << std::endl;
        return(NULL);
    }
    else
    {
        Zombie *horde = new Zombie[N];
        if(horde == NULL)
        {
            std::cout << "Allocation of the horde failed" << std::endl;
            return(NULL);
        }
        else
        {
            for(int i = 0; i < N; i++)
                horde[i].setName(name);
            return(horde);
        }
    }
}
