#include "../include/Intern.hpp"

Intern::Intern(void)
{
    std::cout << "\033[37mDefault constructor for Intern called\033[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "\033[37mCopy constructor for Intern called\033[0m" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "\033[37mAssignation operator for Intern called\033[0m" << std::endl;
    (void)copy;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "\033[34mIntern deconstructor called\033[0m" << std::endl;
}


static AForm* makeShrubbery(const std::string &target){
    return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomy(const std::string &target){
    return (new RobotomyRequestForm(target));
}

static AForm* makePresidential(const std::string &target){
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)const
{
    typedef AForm* (*FormCreator)(const std::string &);

    typedef struct s_FormMap
    {
        std::string name;
        FormCreator creator;
    }t_FormMap;

    static const t_FormMap formTypes[3] = 
    {
        {"shrubbery creation", makeShrubbery},
        {"robotomy request", makeRobotomy},
        {"presidential pardon", makePresidential}
    };

    for (int index = 0; index < this->formRange; index++)
    {
        if (formName == formTypes[index].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (formTypes[index].creator(target));
        }
    }
    std::cerr << "Intern: form \"" << formName << "\" does not exist." << std::endl;
    return (NULL);
}

