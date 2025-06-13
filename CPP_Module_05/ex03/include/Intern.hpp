#pragma once 

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        static const int formRange = 3;
        std::string forms[formRange];
    public:
        Intern(void);
        Intern(const Intern &copy);
        ~Intern();

        Intern &operator=(const Intern &copy);

        AForm* makeForm(const std::string &formName, const std::string &target)const;
        
};