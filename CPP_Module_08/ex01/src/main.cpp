#include "../include/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    try {
        std::cout << "\n\033[32m===== BASIC TEST =====\033[0m" << std::endl;
        Span sp(5);
        sp.addNumber(-12);
        sp.addNumber(3);
        sp.addNumber(-16);
        sp.addNumber(-17);
        sp.addNumber(99);
        std::cout << "\033[33mShortest span: \033[0m" << sp.shortestSpan() << std::endl; 
        std::cout << "\033[33mLongest span: \033[0m" << sp.longestSpan() << std::endl;  

        std::cout << "\n\033[32m===== RANGE INSERT TEST =====\033[0m" << std::endl;
        Span sp2(10);
        std::vector<int> values;
        for (int i = 0; i < 7; ++i)
            values.push_back(i * 3); 
        sp2.addRange(values.begin(), values.end());
        std::cout << "\033[35mShortest span (range): \033[0m" << sp2.shortestSpan() << std::endl;
        std::cout << "\033[35mLongest span (range): \033[0m" << sp2.longestSpan() << std::endl;

        std::cout << "\n\033[32m===== RANGE EXCEEDING TEST =====\033[0m" << std::endl;
        try {
            std::vector<int> tooMany(5, 42); 
            sp2.addRange(tooMany.begin(), tooMany.end()); 
        } catch (const std::exception& e) {
            std::cerr << "\033[31mExpected exception: \033[0m" << e.what() << std::endl;
        }

        std::cout << "\n\033[32m===== 10,000 ELEMENT TEST =====\033[0m" << std::endl;
        Span big(10000);
        std::srand(std::time(NULL));
        std::vector<int> bigData(10000);
        for (int i = 0; i < 10000; ++i)
            bigData[i] = std::rand();

        big.addRange(bigData.begin(), bigData.end());
        std::cout << "\033[34mShortest span: \033[0m" << big.shortestSpan() << std::endl;
        std::cout << "\033[34mLongest span: \033[0m" << big.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "\033[31mUnhandled exception: " << e.what() << std::endl;
    }

    return 0;
}
