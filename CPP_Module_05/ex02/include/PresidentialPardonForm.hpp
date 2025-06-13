#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        static const int gradeToSign = 25;
        static const int gradeToExecute = 5;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat &executor)const;
};