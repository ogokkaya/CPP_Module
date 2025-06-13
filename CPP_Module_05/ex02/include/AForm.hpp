#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    protected:
        void checkExecutionRequirements(const Bureaucrat &executor)const;
    public:
        AForm(void);
        AForm(const std::string &name);
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

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

        class FormNotSignedException: public std::exception{
            public:
            const char* what() const throw();
        };
        
        virtual void execute(const Bureaucrat &executor)const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &ptr);