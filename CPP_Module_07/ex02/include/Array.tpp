#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : array(new T[0]) , _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &copy) : array(new T[copy._size]), _size(copy._size) 
{
    for (unsigned int index = 0; index < copy._size; index++)
        this->array[index] = copy.array[index];
}

template <typename T>
Array<T>    &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        delete[] this->array;
        this->array = new T[copy._size];
        this->_size = copy._size;
        for (unsigned int index = 0; index < copy._size; index++)
            this->array[index] = copy.array[index];
    }
    return(*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array; 
}

template <typename T>
T    &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("\033[31mArray index out of bounds\033[0m");
    return (this->array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index)const
{
    if (index >= _size)
        throw std::out_of_range("\033[31mArray index out of bounds\033[0m");
    return (this->array[index]);
}

template <typename T>
unsigned int Array<T>::size(void)const{ return (this->_size);}

