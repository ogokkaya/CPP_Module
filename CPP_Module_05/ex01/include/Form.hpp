#pragma once 

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        Form(void);
        Form(const std::string &name);
        Form(int signGrade, int execGrade);
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        const std::string getName(void)const;
        bool getIsSigned(void)const;
        int getSignGrade(void)const;
        int getExecGrade(void)const;
        
        void beSigned(Bureaucrat &signer);

        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw();
        };

        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw();
        };

        class FormSignedException : public std::exception{
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &a);