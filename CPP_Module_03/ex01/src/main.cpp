#include "../include/ScavTrap.hpp"

int main()
{
    {
        ScavTrap onur("onur");

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
        onur.guardGate();
    }
    std::cout << std::endl << std::endl;
    {
        ScavTrap	Ati("Ati");

        while (Ati.getHitPoints())
        {
            Ati.takeDamage(20);
            Ati.beRepaired(10);
        }
        Ati.takeDamage(1);
        Ati.guardGate();
    }
    return(0);
}