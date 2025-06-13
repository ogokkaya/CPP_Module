#include "../include/Form.hpp"

Form::Form(void) : name("Default"), isSigned(false), gradeToSign(Bureaucrat::lowestGrade), gradeToExecute(Bureaucrat::lowestGrade)
{
    std::cout << "\033[36mForm constructor was called for the " << this->name << " name"
    << "\ngradeToSign : " << this->gradeToSign << "\ngradeToExecute : " << this->gradeToExecute
    << "\033[0m" << std::endl;
}

Form::Form(const std::string &name) : name(name), isSigned(false), gradeToSign(Bureaucrat::lowestGrade), gradeToExecute(Bureaucrat::lowestGrade)
{
    std::cout << "\033[36mForm constructor was called for the " << this->name << " name"
    << "\ngradeToSign : " << this->gradeToSign << "\ngradeToExecute : " << this->gradeToExecute
    << "\033[0m" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false) , gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade)
        throw Form::GradeTooHighException();
    else if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
        throw Form::GradeTooLowException();
    std::cout << "\033[36mForm constructor was called for the " << this->name << " name"
    << "\ngradeToSign : " << this->gradeToSign << "\ngradeToExecute : " << this->gradeToExecute
    << "\033[0m" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned) , gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    std::cout << "\033[36mForm copy constructor called\033[0m" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "\033[36mAssignation operator for Form called\033[0m" << std::endl;
    if (this != &copy)
        this->isSigned = copy.isSigned;
    return (*this);
}

Form::~Form()
{
    std::cout << "\033[36mForm deconstructor was called for the " << this->name << "\033[0m" << std::endl;
}

const std::string &Form::getName(void)const{return (this->name);}
bool Form::getIsSigned(void)const{return (this->isSigned);}
int Form::getGradeToSign(void)const{return (this->gradeToSign);}
int Form::getGradeToExecute(void)const{return (this->gradeToExecute);}

const char* Form::GradeTooHighException::what() const throw() {return ("Grade is too high");}
const char* Form::GradeTooLowException::what() const throw() {return ("Grade is too low");}
const char* Form::FormIsAlreadySigned::what() const throw() {return ("Form is already signed");}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->isSigned)
        throw Form::FormIsAlreadySigned();
    else if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    else
    {
        std::cout << "\033[35mForm signed by \033[0m" << bureaucrat.getName() << std::endl;
        this->isSigned = true;
    }
}

std::ostream &operator<<(std::ostream &out, const Form &ptr)
{
    out << ptr.getName() << ", form is " 
    << (ptr.getIsSigned() ? "signed" : "not signed")
    << ", sign grade " << ptr.getGradeToSign()
    << ", exec grade " << ptr.getGradeToExecute() << "." << std::endl;
    return (out);
}
