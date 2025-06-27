#include "../include/Data.hpp"
#include "../include/Serialize.hpp"

int main()
{
    Data data("onur", 12, 42.1f);


    uintptr_t raw = Serialize::serialize(&data);
    std::cout << "Serialized address: 0x" << std::hex << raw << std::dec << "\n";

    Data* restored = Serialize::deserialize(raw);

    
    std::cout << "Restored Data:\n";
    std::cout << "  string  : " << restored->_string << "\n";
    std::cout << "  integer : " << restored->_integer << "\n";
    std::cout << "  float   : " << restored->_float << "\n";


    std::cout << "Original ptr : " << &data << "\n";
    std::cout << "Restored ptr : " << restored << "\n";
}