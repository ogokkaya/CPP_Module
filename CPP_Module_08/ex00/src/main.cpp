#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>


int main()
{
    std::vector<int> vec;

    for (int index = 0; index < 3; index++)
    {
        if (index == 0)
            vec.push_back(5);
        else
            vec.push_back(index * 10);
    }
    
    try
    {
        std::cout << "Found: " << *easyfind(vec, 5) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return (0);
}