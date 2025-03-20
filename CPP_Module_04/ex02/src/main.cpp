#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
    std::cout << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "|    IDEA FILL AND DEEP COPY TEST   |" << std::endl;
	std::cout << "=====================================" << std::endl;
	{
		Dog*	toby = new Dog();
		Dog*	mako = new Dog();
		Cat*	michi = new Cat();

		toby->addIdea("I'm hungry.");
		toby->addIdea("I smell something funny.");
		michi->addIdea("I'll go sleep a bit.");
		michi->addIdea("I wonder if that think is huntable.");
		*mako = *toby;
		mako->addIdea("I'll call my human until she comes here.");
		std::cout << std::endl;
        toby->getIdeaFull();
		std::cout << std::endl;
        michi->getIdeaFull();
		std::cout << std::endl;
		mako->getIdeaFull();
		std::cout << std::endl;

		Dog* pipo = new Dog(*toby);

		std::cout << std::endl;
		pipo->getIdeaFull();
		std::cout << std::endl;

		delete toby;
		delete mako;
		delete michi;
		delete pipo;
	}
	return (0);
}
