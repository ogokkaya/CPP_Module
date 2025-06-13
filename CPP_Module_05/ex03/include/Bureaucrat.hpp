#pragma once 

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        static const int lowestGrade = 150;
        static const int highestGrade = 1;
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(const std::string &name);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        const std::string &getName(void)const;
        int getGrade(void)const;
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(AForm &form);
        void executeForm(AForm const &form);

        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                const char * what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out , const Bureaucrat &ptr);