#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"

int main()
{
    // 🔹 1. MateriaSource oluştur ve Materia öğren
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // 🔹 2. Karakter oluştur
    Character* player = new Character("Player1");

    // 🔹 3. MateriaSource'tan yeni Materia'lar üret
    AMateria* m1 = src->createMateria("Ice");
    AMateria* m2 = src->createMateria("Cure");

    // 🔹 4. Karakter Materia'ları envanterine ekliyor
    player->equip(m1);
    player->equip(m2);

    // 🔹 5. Başka bir karakter oluştur ve Materia'lar kullanılıyor
    Character* enemy = new Character("Enemy");
    player->use(0, *enemy);  // Ice kullanıldı
    player->use(1, *enemy);  // Cure kullanıldı

    // 🔹 6. Bellek temizlenmeli!
    delete enemy;
    delete player;
    delete src;

    return 0;
}