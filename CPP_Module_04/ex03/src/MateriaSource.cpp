#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int index = 0; index < MAXLEARNMAT; index++)
        this->library[index] = NULL;
    std::cout << "\033[32mDefault constructor for MateriaSource called\033[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout << "\033[32mCopy constructor for MateriaSource called\033[0m" << std::endl;
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    std::cout << "\033[32mAssignation operator for MateriaSource called\033[0m" << std::endl;
    if(this != &copy)
    {
        int index;
        for(index = 0; index < MAXLEARNMAT; index++)
        {
            if(this->library[index] != NULL)
                delete this->library[index];
            this->library[index] = NULL;
        }
        for(index = 0; index < MAXLEARNMAT; index++)
        {
            if(copy.library[index] != NULL)
                this->library[index] = copy.library[index]->clone();
        }
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{
    for(int index = 0; index < MAXLEARNMAT; index++)
    {
        if(this->library[index] != NULL)
        {
            delete this->library[index];
            this->library[index] = NULL;
        }
    }
    std::cout << "\033[32mDeconstructor for MateriaSource called\033[0m" << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    int index;

    for(index = 0; index < MAXLEARNMAT; index++)
    {
        if(this->library[index] == NULL)
        {
            for(int j = 0; j < MAXLEARNMAT; j++)
            {
                if(this->library[j] == materia)
                {
                    std::cout << "That Materia instance is already in this source" << std::endl;
                    return;
                }
            }
            this->library[index] = materia;
            std::cout << "Materia learn into slot " << index << "." << std::endl;
            break;;
        }
    }
    if(index == MAXLEARNMAT)
        std::cout << "All Materia slots in this resource are currently occupied" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    AMateria *newmateria = NULL;
    int index;

    for(index = 0; index < MAXLEARNMAT; index++)
    {
        if(this->library[index] && type == this->library[index]->getType())
        {
            newmateria = this->library[index]->clone();
            break;
        }
    }
    if(index == MAXLEARNMAT)
        std::cout << "Unknown Materia type" << std::endl;
    return(newmateria);
}