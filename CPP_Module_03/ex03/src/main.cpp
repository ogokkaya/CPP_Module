#include "../include/DiamondTrap.hpp"


int	main(void)
{
    {
        DiamondTrap onur("onur");

        std::cout << "HitPoint: " <<onur.getHitPoints() << std::endl;
        std::cout << "EnergyPoint: " << onur.getEnergyPoints() << std::endl;
        std::cout << "AttackDamage: " << onur.getAttackDamage() << std::endl;
        std::cout << std::endl << std::endl;
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
        onur.highFivesGuys();
        onur.whoAmI();
    }
	std::cout << std::endl << std::endl;
    {
        DiamondTrap	Ati("Ati");

        while (Ati.getHitPoints())
        {
            Ati.takeDamage(20);
            Ati.beRepaired(10);
        }
        Ati.takeDamage(1);
        Ati.guardGate();
        Ati.highFivesGuys();
        Ati.whoAmI();
    }
}