#include <iostream>
#include <../include/Array.hpp>

int main() 
{
    std::cout << "\n###\033[32m Integer Array test \033[0m###\n";
    Array<int> intArr(5);
    for (unsigned int i = 0; i < intArr.size(); ++i)
        intArr[i] = i * 10;

    for (unsigned int i = 0; i < intArr.size(); ++i)
        std::cout << "intArr[\033[33m" << i << "\033[0m] = \033[36m" << intArr[i] << "\n\033[0m";

    std::cout << "\n###\033[32m String Array test \033[0m###\n";
    Array<std::string> strArr(3);
    strArr[0] = "\033[36mHello\033[0m";
    strArr[1] = "\033[36mWorld\033[0m";
    strArr[2] = "\033[36mTemplate\033[0m";

    for (unsigned int i = 0; i < strArr.size(); ++i)
        std::cout << "strArr[\033[33m" << i << "\033[0m] = " << strArr[i] << '\n';

    std::cout << "\n###\033[32m Copy Constructor test \033[0m###\n";
    Array<std::string> copyArr(strArr);
    copyArr[0] = "\033[34mChanged\033[0m";

    std::cout << "Original: " << strArr[0] << ", Copy: " << copyArr[0] << '\n';

    std::cout << "\n###\033[32m Assignment Operator test \033[0m ###\n";
    Array<std::string> assignArr;
    assignArr = strArr;
    assignArr[1] = "\033[34mModified\033[0m";

    std::cout << "Original: " << strArr[1] << ", Assigned: " << assignArr[1] << '\n';

    std::cout << "\n###\033[32m Const Array test \033[0m###\n";
    const Array<int> constArr(intArr);
    for (unsigned int i = 0; i < intArr.size(); ++i)
        std::cout << "intArr[\033[33m" << i << "\033[0m] = \033[36m" << intArr[i] << "\n\033[0m";

    std::cout << "\n###\033[32m Out-of-bounds Access test \033[0m###\n";
    try {
        std::cout << intArr[42] << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    std::cout << "\n###\033[32m Zero-size Array test \033[0m###\n";
    Array<double> emptyArr;
    std::cout << "emptyArr.size() = " << emptyArr.size() << '\n';
    try {
        emptyArr[0] = 3.14;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }
    return (0);
}
