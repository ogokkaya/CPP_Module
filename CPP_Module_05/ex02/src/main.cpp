#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{ 
    try
    {
        Bureaucrat high("HighRank", 1);
        Bureaucrat mid("midRank", 45);
        Bureaucrat low("lowRank", 150);

        std::cout << "\n## \033[34mSHRUBBERY FORM TEST ##\033[0m" << std::endl;
        ShrubberyCreationForm shrub("Garden");
        std::cout << shrub << std::endl;
        {
            low.signForm(shrub);
            high.signForm(shrub);

            low.executeForm(shrub);
            high.executeForm(shrub);
        }
        std::cout << "\n## \033[34mROBOTOMY FORM TEST ##\033[0m" << std::endl;
        {
            RobotomyRequestForm robo("Marvin");
            std::cout << robo << std::endl;

            mid.signForm(robo);
            mid.executeForm(robo);
        }
        std::cout << "\n## \033[34mPRESIDENTIAL PARDON FORM TEST ##\033[0m" << std::endl;
        {
            PresidentialPardonForm pardon("Onur");
            std::cout << pardon << std::endl;

            mid.signForm(pardon);
            high.signForm(pardon);

            mid.executeForm(pardon);
            high.executeForm(pardon);
        }
        std::cout << "\n## \033[34mEXECUTE UNSIGNED FORM TEST ##\033[0m" << std::endl;
        {
            ShrubberyCreationForm shrub("forest");
            mid.executeForm(shrub);
        }

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
