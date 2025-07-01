#include "../include/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "\033[31m[DEBUG]\n\033[33mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\033[0m" << std::endl;
}

void Harl::info(void)
{
    std::cout << "\033[31m[INFO]\n\033[33mI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\033[0m" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "\033[31m[WARNING]\n\033[33mI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\033[0m" << std::endl;
}

void Harl::error(void)
{
    std::cout << "\033[31m[ERROR]\n\033[33mThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}

void Harl::complain( std::string level)
{
    void (Harl::*functionPTR[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string command[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    for(; i < 4; i++)
        if(command[i] == level)
            break;
    switch (i)
    {
		case(0):
			(this->*functionPTR[0])();
		case(1):
			(this->*functionPTR[1])();
		case(2):
			(this->*functionPTR[2])();
		case(3):
			(this->*functionPTR[3])();
			break;
		default:
			std::cout << "\033[32mProbably complaining about insignificant problems\033[0m" << std::endl;
			break;
    }
}               