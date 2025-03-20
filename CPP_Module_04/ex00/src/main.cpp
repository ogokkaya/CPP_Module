#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    //const Animal* meta = new Animal();
    const WrongAnimal* meta = new WrongAnimal();
    //const Animal* j = new Dog();
    //const Animal* i = new Cat();
    const WrongAnimal* i = new WrongCat();
    std::cout << std::endl;
    //std::cout << "Dog : " << j->getType() << std::endl;
    std::cout << "Cat : " << i->getType() << std::endl;
    std::cout << "Animal : "<< meta->getType() << std::endl;
    std::cout << std::endl;
    i->makeSound(); //will output the cat sound!
    //j->makeSound();
    meta->makeSound();
    delete i;
    //delete j;
    delete meta;
    return 0;
}