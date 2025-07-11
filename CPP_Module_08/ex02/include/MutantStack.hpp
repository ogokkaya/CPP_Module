#pragma once 

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack(){}
        MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy){}
        MutantStack &operator=(const MutantStack &copy)
        {
            if (this != &copy)
                std::stack<T, Container>::operator=(copy);
            return (*this);
        }
        ~MutantStack(){}

        typedef typename Container::iterator iterator;

        iterator begin() { return (this->c.begin()); }
        
        iterator end() { return (this->c.end()); }
};