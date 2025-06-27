#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
        std::cout<< "\033[31mInvalid input!\033[0m" << std::endl;;
    return(0);
}