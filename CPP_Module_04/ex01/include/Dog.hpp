#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        ~Dog();
    
        void makeSound(void)const;
        void setIdea(size_t index, std::string idea);
        void getIdea(size_t index)const;
        void addIdea(std::string idea);
        void getIdeaFull(void)const;
};