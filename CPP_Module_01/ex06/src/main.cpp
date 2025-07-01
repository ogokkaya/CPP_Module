#include "../include/Harl.hpp"


int main(int ac, char **av)
{ 
    Harl harl;
    if(ac != 2)
        return(std::cout << "\033[31mInvalid argument. usage: ./harlFilter <options>\033[0m" << std::endl, 0);
    else
    {
        harl.complain(av[1]);
    }
    return(0);
}