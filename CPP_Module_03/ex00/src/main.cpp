#include "../include/ClapTrap.hpp"


int main()
{
    {
        ClapTrap onur("onur");

        onur.attack("Ati");
        onur.attack("Ulas");
        onur.attack("Bilal");
        onur.attack("Ahmet");
        onur.attack("Omer");
        onur.attack("Beyza");
        onur.attack("Gamze");
        onur.attack("Ayse");
        onur.attack("Mehmet");
        onur.attack("Kerim");
        onur.attack("Lale");
        onur.attack("Yasemin");
    }
    std::cout << std::endl << std::endl;
    {
        ClapTrap	Ati("Ati");

        while (Ati.getHitPoints())
        {
            Ati.takeDamage(2);
            Ati.beRepaired(2);
        }
	    Ati.takeDamage(1);
    }
    return(0);
}