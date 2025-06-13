#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(Bureaucrat::lowestGrade)
{
    std::cout << "\033[32mBureaucrat constructor was called for the " << this->name << " name,"
    << "grade : " << this->grade << "\033[0m" << std::endl;
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

Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(Bureaucrat::lowestGrade)
{
    std::cout << "\033[32mBureaucrat constructor was called for the " << this->name << " name,"
    << "grade : " << this->grade << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "\033[32mBureaucrat constructor was called for the " << this->name << " name\033[0m" << std::endl;
    if (grade < Bureaucrat::highestGrade)
        throw GradeTooHighException();
    else if (grade > Bureaucrat::lowestGrade)
        throw GradeTooLowException();
    else
    {
        this->grade = grade;
        std::cout << "\033[32mGrade : " << this->grade << "\033[0m" << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "\033[32mBureaucrat Deconstructor was called for the " << this->name << "\033[0m" << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade == Bureaucrat::lowestGrade)
        throw GradeTooLowException();
    this->grade++;
    std::cout << "New grade is '" << this->grade << "'" << std::endl;
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade == Bureaucrat::highestGrade)
        throw GradeTooHighException();
    this->grade--;
    std::cout << "New grade is '" << this->grade << "'" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){return("Grade is too high");}
const char* Bureaucrat::GradeTooLowException::what() const throw(){return("Grade is too low");}

int Bureaucrat::getGrade(void)const{return(this->grade);}
const std::string &Bureaucrat::getName(void)const{return(this->name);}


void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

std::ostream &operator<<(std::ostream &out , const Bureaucrat &ptr)
{
    out << ptr.getName() << ", bureaucrat grade " << ptr.getGrade() << ".";
    return (out);
}