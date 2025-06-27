#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <iostream>

Base * generate(void)
{
    int i = std::rand() % 3;
    
    if (i == 0)
    {
        std::cout << "\033[32m[generate] ➜ \033[0mA generated." << std::endl;
        return (new A);
    }
    else if (i == 1)
    {
        std::cout << "\033[32m[generate] ➜ \033[0mB generated." << std::endl;
        return (new B);
    }
    else
    {
        std::cout << "\033[32m[generate] ➜ \033[0mC generated." << std::endl;
        return (new C);
    }
}

void identify(Base &p)
{
    std::cout << "\033[33m[identify(reference)] ➜ ";
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "\033[0mActual type: A\033[0m" << std::endl; 
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31mA : " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << "\033[33m[identify(reference)] ➜ ";
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "\033[0mActual type: B" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31mB : " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << "\033[33m[identify(reference)] ➜ ";
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "\033[0mActual type: C" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[31mC : " << e.what() << "\033[0m" << std::endl;
    }
}

void identify(Base* p) 
{
    std::cout << "\033[34m[identify(pointer)] ➜ ";
    if (dynamic_cast<A*>(p)) 
        std::cout << "\033[0mActual type: A" << std::endl;
    else if (dynamic_cast<B*>(p)) 
        std::cout << "\033[0mActual type: B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
        std::cout << "\033[0mActual type: C" << std::endl;
    else 
        std::cout << "\033[31mUnknown type (nullptr)" << std::endl;
}


int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    Base *ptr = generate();
    identify(*ptr);
    identify(ptr);
    delete ptr;
}