#include "../include/Form.hpp"

Form::Form(void) : name("Default"), signGrade(Bureaucrat::lowestGrade), execGrade(lowestGrade)
{
    this->isSigned = false;
    std::cout << "\033[32mForm constructor was called for the " << this->name << " name\033[0m" << std::endl;
}

Form::Form(const std::string &name): name(name), signGrade(lowestGrade) , execGrade(lowestGrade)
{
    this->isSigned = false;
    std::cout << "\033[32mForm constructor was called for the " << this->name << " name\033[0m" << std::endl;
}

Form::Form(int signGrade, int execGrade) : name("Default"), signGrade(signGrade), execGrade(execGrade)
{
    this->isSigned = false;
    std::cout << "\033[32mForm constructor was called for the " << this->name << " name," 
    << " with sign-grade of " << this->signGrade << " and execution-grade of " 
    << this->execGrade << "\033[0m" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade): name(name), signGrade(signGrade), execGrade(execGrade)
{
    this->isSigned = false;
    std::cout << "\033[32mForm constructor was called for the " << this->name << " name," 
    << " with sign-grade of " << this->signGrade << " and execution-grade of " 
    << this->execGrade << "\033[0m" << std::endl;
    if(this->signGrade < Bureaucrat::highestGrade || this->execGrade < Bureaucrat::highestGrade)
        throw(Form::GradeTooHighException());
    else if (this->signGrade > Bureaucrat::lowestGrade || this->execGrade > Bureaucrat::lowestGrade)
        throw(Form::GradeTooLowException());
}

Form::Form(const Form &copy) : name(copy.name + "_copy"), isSigned(false), signGrade(copy.signGrade), execGrade(copy.execGrade)
{
    std::cout << "\033[32mForm copy constructor was called for the " << this->name << " name," 
    << " with sign-grade of " << this->signGrade << " and execution-grade of " 
    << this->execGrade << "\033[0m" << std::endl;
    *this = copy;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "\033[32mAssignation operator for Form called\033[0m" << std::endl;
    if(this != &copy)
        this->isSigned = copy.isSigned;
    return(*this);
}

Form::~Form()
{
    std::cout << "\033[32mDeconstructor for " << this->name << " called\033[0m" << std::endl;
}

void Form::beSigned(Bureaucrat &signer)
{
    if(signer.getGrade() > this->signGrade)
        throw(Form::GradeTooLowException());
    else if(this->isSigned == false)
    {
        this->isSigned = true;
        std::cout << this->name << " Form was signed by " << signer.getName() << std::endl;
    }
    else
        throw(Form::FormSignedException());
}

const char* Form::GradeTooHighException::what() const throw() {return("Grade is too high");}
const char* Form::GradeTooLowException::what() const throw() {return("Grade is too low");}
const char* Form::FormSignedException::what() const throw() {return("Form is already signed");}

const std::string Form::getName(void)const {return(this->name);}

bool Form::getIsSigned(void)const {return(this->isSigned);}

int Form::getSignGrade(void)const {return(this->signGrade);}

int Form::getExecGrade(void)const {return(this->execGrade);}

std::ostream &operator<<(std::ostream &out, const Form &a)
{
    out << "Form " << a.getName() << " is ";
    if(a.getIsSigned())
        out << "signed";
    else
        out << "not signed";
    out << " with sign-grade of " << a.getSignGrade() << " and execution-grade of " 
    << a.getExecGrade() << std::endl;
    return(out);
}
