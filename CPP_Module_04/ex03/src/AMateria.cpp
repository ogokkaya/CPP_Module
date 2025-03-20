#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria()
{
    this->type = "";
    std::cout << "\033[32mDefault constructor for AMateria called\033[0m" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
    std::cout << "\033[32mAMateria founder was called for the "<< this->getType() << " type\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    std::cout << "\033[32mCopy constructor for AMateria called\033[0m" << std::endl;
    *this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    std::cout << "\033[32mAssignation operator for AMateria called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.getType();
    return(*this);
}

AMateria::~AMateria()
{
    std::cout << "\033[32mDeconstructor for AMateria called\033[0m" << std::endl;
}


std::string const &AMateria::getType()const
{
    return(this->type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Generic materia used over " << target.getName()  << ", what a waste." << std::endl;
}