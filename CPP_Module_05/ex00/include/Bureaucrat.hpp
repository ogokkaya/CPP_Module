#pragma once

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        static const int highestGrade = 1;
        static const int lowestGrade = 150;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        const std::string &getName(void)const;
        int getGrade(void)const;
        void incrementGrade(void);
        void decrementGrade(void);

        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
};

std::ostream  &operator<<(std::ostream &o, const Bureaucrat &ptr);