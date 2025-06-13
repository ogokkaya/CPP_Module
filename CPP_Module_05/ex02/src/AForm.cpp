#include "../include/AForm.hpp"

AForm::AForm(void) : name("Default"), isSigned(false), gradeToSign(Bureaucrat::lowestGrade), gradeToExecute(Bureaucrat::lowestGrade)
{
    std::cout << "\033[36mAForm constructor was called for the " << this->name << " name"
    << "\ngradeToSign : " << this->gradeToSign << "\ngradeToExecute : " << this->gradeToExecute
    << "\033[0m" << std::endl;
}

AForm::AForm(const std::string &name) : name(name), isSigned(false), gradeToSign(Bureaucrat::lowestGrade), gradeToExecute(Bureaucrat::lowestGrade)
{
    std::cout << "\033[36mAForm constructor was called for the " << this->name << " name"
    << "\ngradeToSign : " << this->gradeToSign << "\ngradeToExecute : " << this->gradeToExecute
    << "\033[0m" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false) , gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
        throw AForm::GradeTooLowException();
    std::cout << "\033[36mAForm constructor was called for the " << this->name << " name"
    << "\ngradeToSign : " << this->gradeToSign << "\ngradeToExecute : " << this->gradeToExecute
    << "\033[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned) , gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    std::cout << "\033[36mAForm copy constructor called\033[0m" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    std::cout << "\033[36mAssignation operator for AForm called\033[0m" << std::endl;
    if (this != &copy)
        this->isSigned = copy.isSigned;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "\033[36mAForm deconstructor was called for the " << this->name << "\033[0m" << std::endl;
}

const std::string &AForm::getName(void)const{return (this->name);}
bool AForm::getIsSigned(void)const{return (this->isSigned);}
int AForm::getGradeToSign(void)const{return (this->gradeToSign);}
int AForm::getGradeToExecute(void)const{return (this->gradeToExecute);}

const char* AForm::GradeTooHighException::what() const throw() {return ("Grade is too high");}
const char* AForm::GradeTooLowException::what() const throw() {return ("Grade is too low");}
const char* AForm::FormIsAlreadySigned::what() const throw() {return ("Form is already signed");}
const char* AForm::FormNotSignedException::what() const throw() {return ("Form is not signed");}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->isSigned)
        throw AForm::FormIsAlreadySigned();
    else if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "\033[35mForm signed by \033[0m" << bureaucrat.getName() << std::endl;
        this->isSigned = true;
    }
}

void AForm::checkExecutionRequirements(const Bureaucrat &executor)const
{
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &ptr)
{
    out << ptr.getName() << ", Form is " 
    << (ptr.getIsSigned() ? "signed" : "not signed")
    << ", sign grade " << ptr.getGradeToSign()
    << ", exec grade " << ptr.getGradeToExecute() << "." << std::endl;
    return (out);
}
