#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"

int main()
{
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character* player = new Character("Player1");

    AMateria* m1 = src->createMateria("Ice");
    AMateria* m2 = src->createMateria("Cure");

    player->equip(m1);
    player->equip(m2);

    Character* enemy = new Character("Enemy");
    player->use(0, *enemy);  // Ice kullanıldı
    player->use(1, *enemy);  // Cure kullanıldı

    delete enemy;
    delete player;
    delete src;

    return 0;
}