#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute) , target("Default") 
{
    std::cout << "\033[37mPresidentialPardonForm constructor was called for the " << target 
    << " name\n" << "gradeToSign : " << gradeToSign << "\ngradeToExecute : " << gradeToExecute << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute), target(target) 
{
    std::cout << "\033[37mPresidentialPardonForm constructor was called for the " << target 
    << " name\n" << "gradeToSign : " << gradeToSign << "\ngradeToExecute : " << gradeToExecute << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{
    std::cout << "\033[37mPresidentialPardonForm copy constructor called\033[0m" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "\033[37mAssignation operator for PresidentialPardonForm called\033[0m" << std::endl;
    if (this != &copy)
        this->target = copy.target;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "\033[37mPresidentialPardonForm deconstructor was called for the " << target << "\033[0m"<<  std::endl;
}


void PresidentialPardonForm::execute(const Bureaucrat &executor)const
{
    AForm::checkExecutionRequirements(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}