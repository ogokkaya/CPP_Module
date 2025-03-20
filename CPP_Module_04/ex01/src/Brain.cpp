#include "../include/Brain.hpp"

Brain::Brain()
{
    for(int index = 0; index < MAXIDEA; index++)
        this->ideas[index] = "";
    std::cout << "\033[32mDefault constructor for Brain called\033[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "\033[32mCopy constructor for Brain called\033[0m" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
    std::cout << "\033[32mAssignation operator for Brain called\033[0m" << std::endl;
    if(this != &copy)
    {
        for(int index = 0; index < MAXIDEA; index++)
        {
            if(copy.ideas[index] != "")
                this->ideas[index] = copy.ideas[index];
        }
    }
    return(*this);
}

Brain::~Brain()
{
    std::cout << "\033[32mDeconstructor for Brain called\033[0m" << std::endl;
}

const std::string Brain::getIdea(size_t index)const
{
    if(index < MAXIDEA)
        return(this->ideas[index]);
    else
        std::cout << "\033[31m[Error]\033[0m \033[33mInvalid index! A brain can only store 100 ideas (0-99).\033[0m" << std::endl;
    return("");
}

const std::string *Brain::getIdeaAddress(size_t index)const
{
    if(index < MAXIDEA)
        return(&this->ideas[index]);
    else
        std::cout << "\033[31m[Error]\033[0m \033[33mInvalid index! A brain can only store 100 ideas (0-99).\033[0m" << std::endl;
    return(NULL);
}

void Brain::setIdea(size_t index, std::string idea)
{
    if(index < MAXIDEA)
        this->ideas[index] = idea;
    else
        std::cout << "\033[31m[Error]\033[0m \033[33mInvalid index! A brain can only store 100 ideas (0-99).\033[0m" << std::endl;
}

void Brain::addIdea(std::string idea)
{
    int index;
    for(index = 0 ; index < MAXIDEA; index++)
    {
        if(this->ideas[index] == "")
        {
            this->ideas[index] = idea;
            break;
        }
    }
    if(index == MAXIDEA)
        std::cout << "This animal can't have more new ideas until forgets something" << std::endl;
}