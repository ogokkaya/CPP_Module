#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        static const int gradeToSign = 72;
        static const int gradeToExecute = 45;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor)const;
};