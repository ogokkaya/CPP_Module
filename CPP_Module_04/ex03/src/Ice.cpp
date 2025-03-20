#include "../include/Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
    std::cout << "\033[32mDefault constructor for Ice called\033[0m" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
    std::cout << "\033[32mCopy constructor for Ice called\033[0m" << std::endl;
    *this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
    std::cout << "\033[32mAssignation operator for Ice called\033[0m" << std::endl;
    if(this != &copy)
        this->type = copy.getType();
    return(*this);
}

Ice::~Ice()
{
    std::cout << "\033[32mDeconstructor for Ice called\033[0m" << std::endl;
}

AMateria *Ice::clone()const
{
    Ice *newIce = new(std::nothrow) Ice();
    if(!newIce)
    {
        std::cerr << "\033[31m[Error]\033[0m Memory allocation for Ice failed!" << std::endl;
        std::cerr << "\033[33mExiting the process now.\033[0m" << std::endl;
        exit(1);
    }
    return(newIce);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}