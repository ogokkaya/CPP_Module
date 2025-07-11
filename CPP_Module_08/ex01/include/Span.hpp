#pragma once 

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int limit;
    public:
        Span();
        Span(unsigned int limit);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        void addNumber(int number);
        int shortestSpan(void)const; 
        int longestSpan(void)const;
        template <typename ImputIt>
        void addRange(ImputIt begin, ImputIt end)
        {
            std::ptrdiff_t count = std::distance(begin, end);
            if (count < 0)
                throw   std::invalid_argument("Invalid iterator range");
            else if (static_cast<unsigned int>(count) + vec.size() > limit)
                throw std::out_of_range("Adding this range would exceed the span's capacity.");
            vec.insert(vec.end(), begin, end);
        }
};