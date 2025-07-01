#pragma once

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &copy);
        ~Array();

        unsigned int size()const;
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index)const;
};

#include "Array.tpp"