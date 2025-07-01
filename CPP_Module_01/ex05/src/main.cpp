#include "../include/Harl.hpp"


int main()
{
    Harl harl;

    std::cout << "Something that Harl's gonna tell you" << std::endl << std::endl;
    harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("DEBUG");
    std::cout << "\nMake him talk\n\033[31m* \033[0m";
    std::string input;
    while(std::getline(std::cin, input))
    {
        harl.complain(input);
        std::cout << std::endl;
        std::cout << "\033[31m* \033[0m";
    }
    if(std::cin.eof())
    {
        std::cout << "\033[31mYou Pressed ^D. Exiting\033[0m" << std::endl;
        return(0);
    }
    return(0);
}