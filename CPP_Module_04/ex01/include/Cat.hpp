#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        ~Cat();

        void makeSound(void)const;
        void setIdea(size_t index, std::string idea);
        void getIdea(size_t index)const;
        void addIdea(std::string idea);
        void getIdeaFull(void)const;
};