#pragma once 

#include "Data.hpp"

class Serialize
{
    private:
        Serialize();
        Serialize(const Serialize &copy);
        Serialize &operator=(const Serialize &copy);
        ~Serialize();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};