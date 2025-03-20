#pragma once

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#define MAXLEARNMAT 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *library[MAXLEARNMAT];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &copy);
        ~MateriaSource();

        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);
};
