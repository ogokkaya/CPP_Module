#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"


int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat lowbie("lowbie", 150);

    std::cout << "\n## \033[34mSHRUBBERY TEST ##\033[0m" << std::endl;
	AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (shrub)
    {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        std::cout << "\n\033[31mInadequate grade\033[0m" << std::endl;
        lowbie.signForm(*shrub);
        lowbie.executeForm(*shrub);
        std::cout << std::endl;
        delete shrub;
    }
    std::cout << "\n## \033[34mROBOTOMY TEST ##\033[0m" << std::endl;
	AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robot)
    {
        boss.signForm(*robot);
        boss.executeForm(*robot);
        std::cout << "\n\033[31mInadequate grade\033[0m" << std::endl;
        lowbie.signForm(*robot);
        lowbie.executeForm(*robot);
        std::cout << std::endl;
        delete robot;
    }
    std::cout << "\n## \033[34mPRESIDENTIAL PARDON TEST ##\033[0m" << std::endl;
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (pardon)
    {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        std::cout << "\n\033[31mInadequate grade\033[0m" << std::endl;
        lowbie.signForm(*pardon);
        lowbie.executeForm(*pardon);
        std::cout << std::endl;
        delete pardon;
    }
    std::cout << "\n## \033[34mINVALID FORM TEST ##\033[0m" << std::endl;
    AForm* invalid = someRandomIntern.makeForm("nonexistent form", "Nobody");
	if (invalid)
		delete invalid;
    return (0);
}
