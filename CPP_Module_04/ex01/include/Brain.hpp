#pragma once

#include <iostream>
#define MAXIDEA 100

class Brain
{
    private:
        std::string ideas[MAXIDEA];
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        virtual ~Brain();
    
        const std::string getIdea(size_t index)const;
        const std::string *getIdeaAddress(size_t index)const;
        void addIdea(std::string idea);
        void setIdea(size_t index, std::string idea);
};