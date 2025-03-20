#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual ~Animal();
    
        virtual void makeSound(void)const;
        std::string const &getType(void)const;
        void setType(std::string type);
};