#pragma once


#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        static const int gradeToSign = 145;
        static const int gradeToExecute = 137;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

        void execute(const Bureaucrat &executor)const;

};
