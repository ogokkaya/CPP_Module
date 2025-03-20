#pragma once

#include "ICharacter.hpp"
#define MAXMATERIA 4

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[MAXMATERIA];
    public:
        Character();
        Character(const std::string &name);
        Character(const Character &copy);
        Character &operator=(const Character &copy);
        ~Character();

        std::string const &getName()const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};