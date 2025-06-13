#include "../include/Bureaucrat.hpp"


int main()
{
    try
    {
        std::cout << "\033[35m## Correct Bureaucrat creation ##\033[0m" << std::endl;
        Bureaucrat john("John", 100);
        std::cout << john << std::endl;

        std::cout << "\n\033[35m## Incrementing Grade ##\033[0m" << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;

        std::cout << "\n\033[35m## Decrementing Grade ##\033[0m" << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;

        std::cout << "\n\033[35m## Invalid Bureaucrat (Too High) ##\033[0m" << std::endl;
        Bureaucrat error("Error", 0);
        //std::cout << "\n\033[35m## Invalid Bureaucrat (Too Low) ##\033[0m" << std::endl;
        //Bureaucrat error("Error", 150);
    }
    catch(const std::exception &e)
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n\033[35m## Edge case (Grade 1 and 150) ##\033[0m" << std::endl;
        Bureaucrat EdgeCase1("EdgeCase1", 1);
        EdgeCase1.incrementGrade();
    }
    catch(const std::exception &e)
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << "\n" << std::endl;
    }
    try
    {
        Bureaucrat EdgeCase150("EdgeCase150", 150);
        EdgeCase150.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }

    return (0);
}
