#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new(std::nothrow) Brain();
    if(this->brain == NULL)
    {
        std::cerr << "\033[31m[Error]\033[0m Memory allocation for Brain failed!" << std::endl;
        std::cerr << "\033[33mExiting the process now.\033[0m" << std::endl;
        exit(1);
    }
    std::cout << "\033[32mDefault constructor for Dog called\033[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "\033[32mCopy constructor for Dog called\033[0m" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "\033[32mAssignation operator for Dog called\033[0m" << std::endl;
    if(this != &copy)
    {
        this->type = copy.getType();
        if(this->brain)
            delete(this->brain);
        this->brain = new(std::nothrow) Brain();
        if(this->brain != NULL)
        {
            for(int index = 0; index < MAXIDEA; index++)
            {
                if(copy.brain->getIdea(index) != "")
                    this->brain->setIdea(index, copy.brain->getIdea(index));
            }
        }
        else
        {
            std::cerr << "\033[31m[Error]\033[0m Memory allocation for Brain failed!" << std::endl;
            std::cerr << "\033[33mExiting the process now.\033[0m" << std::endl;
            exit(1);
        }
    }
    return(*this);
}

Dog::~Dog()
{
    delete(this->brain);
    this->brain = NULL;
    std::cout << "\033[32mDeconstructor for Dog called\033[0m" << std::endl;
}

void Dog::makeSound(void)const
{
    std::cout << this->getType() << " : HavHav" << std::endl;
}

void Dog::setIdea(size_t index, std::string idea)
{
    this->brain->setIdea(index, idea);
}

void Dog::getIdea(size_t index)const
{
    std::cout << this->getType() << ": "
    << this->brain->getIdea(index) << "'s address: " << this->brain->getIdeaAddress(index) << std::endl;
}

void Dog::addIdea(std::string idea)
{
    this->brain->addIdea(idea);
}

void Dog::getIdeaFull(void)const
{
    for(int index = 0; index < MAXIDEA; index++)
    {
        if(this->brain->getIdea(index) != "")
        {
            std::cout << this->getType() << ", index " << index << " idea: "
            << this->brain->getIdea(index) << "'s address: " << this->brain->getIdeaAddress(index) << std::endl;
        }
    }
}
