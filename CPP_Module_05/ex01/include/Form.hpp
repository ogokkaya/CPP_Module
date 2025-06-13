#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;  
    public:
        Form(void);
        Form(const std::string &name);
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();

        const std::string &getName(void)const;
        bool getIsSigned(void)const;
        int getGradeToSign(void)const;
        int getGradeToExecute(void)const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormIsAlreadySigned : public std::exception{
            public:
                const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream &out, const Form &ptr);