#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("Bureaucrat 1", 1);
		Bureaucrat b2("Bureaucrat 2", 150);
		Form f1("Form 1", 1, 1);
		Form f2("Form 2", 150, 150);
		Form *f = NULL;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
 

		b1.signForm(&f1);
		b2.signForm(&f2);

		b1.signForm(f);


		b1.signForm(&f2);
		b2.signForm(&f1);


		b1.incrementGrade();

		b2.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}