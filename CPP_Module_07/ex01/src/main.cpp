#include "../include/iter.hpp"

template <typename digit>
void square(digit &a)
{
	a *= a;
}

void toUpperorLower(std::string &string)
{
    for (size_t index = 0; index < string.length(); index++)
    {
        if (string[index] <= 'z' && string[index] >= 'a')
            string[index] = std::toupper(string[index]);
        else if (string[index] <= 'Z' && string[index] >= 'A')
            string[index] = std::tolower(string[index]);
    }
}

int main ()
{
	std::cout << "========== Template for int ==========" << std::endl;
	int intArry[] = {1, 2, 3, 4, 5};
	::iter(intArry, (int)sizeof(intArry)/sizeof(intArry[0]), square<int>);
	displayArray(intArry,sizeof(intArry)/sizeof(intArry[0]));

    std::cout << "========== Template for float ==========" << std::endl;
	float floatArry[] = {1.2, 2.1, 3.4, 4.6, 5.1};
	::iter(floatArry, (int)sizeof(floatArry)/sizeof(floatArry[0]), square<float>);
	displayArray(floatArry,sizeof(floatArry)/sizeof(floatArry[0]));
	
	std::cout << "========== Template for string ==========" << std::endl;
	std::string stringArry[] = {"oNUr", "GoKKaYa", "2001"};
	::iter(stringArry, (int)(sizeof(stringArry)/sizeof(stringArry[0])), toUpperorLower);
	displayArray(stringArry, sizeof(stringArry)/sizeof(stringArry[0]));
	
	return 0;
}