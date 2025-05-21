#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(Bureaucrat::lowestGrade)
{
    std::cout << "\033[32mBureaucrat constructor was called for the " << this->name << " name,"
    << "grade : " << this->grade << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(Bureaucrat::lowestGrade)
{
    std::cout << "\033[32mBureaucrat constructor was called for the " << this->name << " name,"
    << "grade : " << this->grade << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "\033[32mBureaucrat constructor was called for the " << this->name << " name\033[0m" << std::endl;
    if(grade < Bureaucrat::highestGrade)
        throw GradeTooHighException();
    else if (grade > Bureaucrat::lowestGrade)
        throw GradeTooLowException();
    else
    {
        this->grade = grade;
        std::cout << "Grade : " << this->grade << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    std::cout << "\033[32mCopy constructor for Bureaucrat called\033[0m" << std::endl;
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "\033[32mAssignation operator for Bureaucrat called\033[0m" << std::endl;
    if(this != &copy)
        this->grade = copy.grade;
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "\033[32mDeconstructor for Bureaucrat called\033[0m" << std::endl;
}

const std::string &Bureaucrat::getName(void)const
{
    return(this->name);
}

int Bureaucrat::getGrade(void)const
{
    return(this->grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low");
}

const char* Bureaucrat::invalidFormException::what() const throw() {return("Invalid form");}

void Bureaucrat::decrementGrade(void)
{
    if(this->grade == lowestGrade) 
        throw GradeTooLowException();
    this->grade++;
    std::cout << "New grade is '" << this->grade << "'" << std::endl;
}

void Bureaucrat::incrementGrade(void)
{
    if(this->grade == highestGrade)
        throw GradeTooHighException();
    this->grade--;
    std::cout << "New grade is '" << this->grade << "'" << std::endl;
}

std::ostream   &operator<<(std::ostream &o, const Bureaucrat &ptr)
{   
    o << ptr.getName() << ", bureaucrat grade " << ptr.getGrade();
    return(o);
}

void Bureaucrat::signForm(Form *form)
{
    try
    {
        if(form == NULL)
            throw (Bureaucrat::invalidFormException());
        form->beSigned(*this);
        std::cout << this->name << " signs " << form->getName() << std::endl;
    }
    catch(const Bureaucrat::invalidFormException& e)
    {
        std::cout << this->name << " cannot sign the form because " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " cannot sign " << form->getName() << " because " << e.what() << std::endl;
    }
}