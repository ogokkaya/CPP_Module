#pragma once

#include <iostream>
#include "../include/Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        
        static const int highestGrade = 1;
        static const int lowestGrade = 150;
        
        const std::string &getName(void)const;
        int getGrade(void)const;
        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(Form *form);

        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };

        class invalidFormException : public std::exception{
            public:
                const char* what() const throw();
        };
};

std::ostream  &operator<<(std::ostream &o, const Bureaucrat &ptr);