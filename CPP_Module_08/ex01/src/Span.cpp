#include "../include/Span.hpp"


Span::Span() : vec(), limit(0){}

Span::Span(unsigned int limit) : vec(), limit(limit){
    this->vec.reserve(limit);
}

Span::~Span(){}

Span::Span(const Span &copy){ *this = copy;}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->vec = copy.vec;
        this->limit = copy.limit;
    }
    return (*this);
}


void Span::addNumber(int number)
{
    std::cout << "\033[35mContainer size: \033[0m" << this->vec.size() << std::endl;
    if (this->vec.size() == this->limit)
        throw std::out_of_range("Container capacity full");
    this->vec.push_back(number);
}

int Span::shortestSpan()const
{
    if (this->vec.size() <= 1)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted(this->vec);
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diffs;
    for (size_t index = 1; index < sorted.size(); index++)
        diffs.push_back(sorted[index] - sorted[index - 1]);
    
    return (*std::min_element(diffs.begin(), diffs.end()));
}

int Span::longestSpan()const
{
    if (this->vec.size() <= 1)
        throw std::logic_error("Not enough numbers to find a span");
    
    int minVal = *std::min_element(this->vec.begin(), this->vec.end());
    int maxVal = *std::max_element(this->vec.begin(), this->vec.end());

    return (maxVal - minVal);
}