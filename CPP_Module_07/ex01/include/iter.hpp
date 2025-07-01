#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F function)
{
    for (size_t index = 0; index < length; index++)
        function(array[index]);
}

template <typename T>
void displayArray(T *array, size_t length)
{
    for (size_t index = 0; index < length; index++)
        std::cout << array[index] << std::endl;
}