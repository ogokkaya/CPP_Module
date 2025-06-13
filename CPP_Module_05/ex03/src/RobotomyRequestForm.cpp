#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute), target("Default")
{
    std::cout << "\033[37mRobotomyRequestForm constructor was called for the " << target 
    << " name\n" << "gradeToSign : " << gradeToSign << "\ngradeToExecute : " << gradeToExecute << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute), target(target)
{
    std::cout << "\033[37mRobotomyRequestForm constructor was called for the " << target 
    << " name\n" << "gradeToSign : " << gradeToSign << "\ngradeToExecute : " << gradeToExecute << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
    std::cout << "\033[37mRobotomyRequestForm copy constructor called\033[0m" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "\033[37mAssignation operator for RobotomyRequestForm called\033[0m" << std::endl;
    if (this != &copy)
        this->target = copy.target;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "\033[37mRobotomyRequestForm deconstructor was called for the " << target << "\033[0m"<<  std::endl;
}


void RobotomyRequestForm::execute(const Bureaucrat &executor)const
{
    AForm::checkExecutionRequirements(executor);

    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << "* DRILLING NOISES *" << std::endl;

    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}