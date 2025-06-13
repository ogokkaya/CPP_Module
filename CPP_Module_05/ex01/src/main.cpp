#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
    try
    {
        std::cout << "\n## \033[34mCreating valid Form and Bureaucrat \033[0m##" << std::endl;
        Bureaucrat bob("Bob" , 50);
        Form taxForm("TaxForm", 100, 50);

        std::cout << "\n" << bob << std::endl;
        std::cout << taxForm << std::endl;

        std::cout << "\033[36mTrying to sign the form with Bob...\033[0m" << std::endl;
        bob.signForm(taxForm);

        std::cout << "\n" << taxForm << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n##\033[34m Bureucrat with too low grade tries to sign \033[0m##" << std::endl;
        Bureaucrat john("John", 140);
        Form topSecret("TopSecret", 50, 20);

        std::cout << "\n" << john << std::endl;
        std::cout << topSecret << std::endl;

        john.signForm(topSecret);
        std::cout << topSecret << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n##\033[34m Form already signed \033[0m##" << std::endl;
        Bureaucrat ali("Ali", 1);
        Form passport("Passport", 10, 5);

        ali.signForm(passport);
        std::cout << std::endl << passport << std::endl;
        ali.signForm(passport);
    }
    catch(const std::exception &e)
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n##\033[34m Invalid Form creation (invalid grades) \033[0m##" << std::endl;
        Form invalidForm("invalidForm", 0, 200);
    }
    catch(const std::exception &e)
    {
        std::cerr << "\033[31mException: \033[0m" << e.what() << std::endl;
    }

    return (0);
}
