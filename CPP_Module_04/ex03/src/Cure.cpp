#include "../include/Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "\033[32mDefault constructor for Cure called\033[0m" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    std::cout << "\033[32mCopy constructor for Cure called\033[0m" << std::endl;
    *this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
    std::cout << "\033[32mAssignation operator for Cure called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.getType();
    return(*this);
}

Cure::~Cure()
{
    std::cout << "\033[32mDeconstructor for Cure called\033[0m" << std::endl;
}

AMateria *Cure::clone()const
{
    Cure *newCure = new(std::nothrow) Cure();
    if(!newCure)
    {
        std::cerr << "\033[31m[Error]\033[0m Memory allocation for Cure failed!" << std::endl;
        std::cerr << "\033[33mExiting the process now.\033[0m" << std::endl;
        exit(1);
    }
    return(newCure);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}