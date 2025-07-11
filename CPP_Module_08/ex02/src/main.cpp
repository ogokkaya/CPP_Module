#include "../include/MutantStack.hpp"
#include <iostream>
#include <list>

int main() 
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "\n\033[33mTop: \033[0m" << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "\033[32mSize after pop: \033[0m" << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\033[32m### Iterating MutantStack ###\033[0m" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "\n\033[32m### Compare with  std::list ###\033[0m" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}
