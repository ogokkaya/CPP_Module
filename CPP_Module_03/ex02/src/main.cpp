#include "../include/FragTrap.hpp"

int	main(void)
{
	{
        FragTrap onur("onur");

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
        onur.highFivesGuys();
    }
    std::cout << std::endl << std::endl;
	{
        FragTrap	Ati("Ati");

        while (Ati.getHitPoints())
        {
            Ati.takeDamage(20);
            Ati.beRepaired(10);
        }
        Ati.takeDamage(1);
        Ati.highFivesGuys();
    }
    return(0);
}