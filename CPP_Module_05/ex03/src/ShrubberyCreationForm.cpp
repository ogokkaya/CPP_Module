#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute), target("Default")
{
    std::cout << "\033[37mShrubberyCreationForm constructor was called for the " << target 
    << " name\n" << "gradeToSign : " << gradeToSign << "\ngradeToExecute : " << gradeToExecute << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute), target(target)
{
    std::cout << "\033[37mShrubberyCreationForm constructor was called for the " << target 
    << " name\n" << "gradeToSign : " << gradeToSign << "\ngradeToExecute : " << gradeToExecute << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
    std::cout << "\033[37mShrubberyCreationForm copy constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "\033[37mAssignation operator for ShrubberyCreationForm called\033[0m" << std::endl;
    if (this != &copy)
        this->target = copy.target;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "\033[37mShrubberyCreationForm deconstructor was called for the " << target << "\033[0m"<<  std::endl;
}


void ShrubberyCreationForm::execute(const Bureaucrat &executor)const
{
    AForm::checkExecutionRequirements(executor);
    std::ofstream	outFile;
    
    outFile.open((this->target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
    if (!outFile.is_open())
        throw std::runtime_error("Failed to open output file");
    else
    {
       outFile << "        ###\n"
               << "       #o###\n"
               << "     #####o###\n"
               << "    #o#\\#|#/###\n"
               << "     ###\\|/#o#\n"
               << "      # }|{  #\n"
               << "        }|{\n"
               << "\nSigned by: " << executor.getName()<<std::endl;
		outFile.close();
    }
}