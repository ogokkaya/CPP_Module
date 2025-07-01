#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "\033[33mAddress of string:\t" << &string << std::endl; 
    std::cout << "\033[31mAddress of stringPTR:\t" << stringPTR << std::endl;
    std::cout << "\033[33mAddress of stringREF:\t" << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "\033[33mValue of string:\t" << string << std::endl;
    std::cout << "\033[31mValue of stringREF:\t"<< stringREF  << std::endl;
    std::cout << "\033[33mValue pointed to by:\t"<< *stringPTR << "\033[0m" << std::endl;
}