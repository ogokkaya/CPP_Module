#include "../include/Character.hpp"

Character::Character()
{
    this->name = "";
    for(int index = 0; index < MAXMATERIA; index++)
        this->inventory[index] = NULL;
    std::cout << "\033[32mDefault constructor for Character called\033[0m" << std::endl;
}

Character::Character(const std::string &name)
{
    this->name = name;
    for(int index = 0; index < MAXMATERIA; index++)
        this->inventory[index] = NULL;
    std::cout << "\033[32mCharacter constructor was called for the "<< this->getName() << " name\033[0m" << std::endl;
}

Character::Character(const Character &copy)
{
    std::cout << "\033[32mCopy constructor for Character called\033[0m" << std::endl;
    *this = copy;
}

Character &Character::operator=(const Character &copy)
{
    std::cout << "\033[32mAssignation operator for Character called\033[0m" << std::endl;
    if(this != &copy)
    {
        int index;
        for(index = 0; index < MAXMATERIA; index++)
        {
            if(this->inventory[index])
                delete this->inventory[index];
            this->inventory[index] = NULL;
        }
        for(index = 0; index < MAXMATERIA; index++)
        {
            if(copy.inventory[index])
                this->inventory[index] = copy.inventory[index]->clone();
            else
                this->inventory[index] = NULL;
        }
    }
    return(*this);
}

Character::~Character()
{
    for(int index = 0; index < MAXMATERIA; index++)
    {
        if(this->inventory[index])
            delete this->inventory[index];
    }
    std::cout << "\033[32mCharacter deconstructor was called for the " << this->name << " name\033[0m" << std::endl;
}

std::string const &Character::getName()const
{
    return(this->name);
}

void Character::equip(AMateria *m)
{
    if(!m)
    {
        std::cout << "\033[31m[Error]\033[0m invalid AMateria address" << std::endl;
        return;
    }
    else
    {
        int index;
        for(index = 0; index < MAXMATERIA; index++)
        {
            if(!this->inventory[index])
            {
                this->inventory[index] = m;
                std::cout << this->name << " equipped a " << m->getType() 
                << " Materia in slot " << index << std::endl;
                return;
            }
        }
    }
    std::cout << "\033[31m" <<this->name << "'s inventory is full! Cannot equip more Materia\033[0m" << std::endl;
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < MAXMATERIA)
    {
        if(this->inventory[idx])
        {
            std::cout << this->name << " has unequipped a " 
                      << this->inventory[idx]->getType() 
                      << " Materia from inventory slot: " << idx 
                      << ". The slot is now empty." << std::endl;
            this->inventory[idx] = NULL;
        }
        else
            std::cout << this->name << "'s invertory has no materia in that slot" << std::endl;
    }
    else
        std::cout << "Invalid inventory slot: " << idx << "." << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if(idx >= 0 && idx < MAXMATERIA && this->inventory[idx])
        this->inventory[idx]->use(target);
    else
        std::cout << this->name << "'s invertory has no materia in that slot" << std::endl;
}