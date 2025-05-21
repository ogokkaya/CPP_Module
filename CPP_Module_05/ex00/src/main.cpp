#include "../include/Bureaucrat.hpp"

int main() {
    try {
        std::cout << "✅ Correct Bureaucrat Creation\n";
        Bureaucrat b1("John", 100);
        std::cout << b1 << std::endl;

        std::cout << "\n⏫ Incrementing Grade\n";
        b1.incrementGrade();
        std::cout << b1 << std::endl;

        std::cout << "\n⏬ Decrementing Grade\n";
        b1.decrementGrade();
        std::cout << b1 << std::endl;

        std::cout << "\n🚫 Invalid Bureaucrat (Too High)\n";
        Bureaucrat b2("Error", 0);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n🚫 Invalid Bureaucrat (Too Low)\n";
        Bureaucrat b3("Error2", 151);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n🚀 Edge Case (Grade 1 and 150)\n";
        Bureaucrat top("Top", 1);
        Bureaucrat bottom("Bottom", 150);
        std::cout << top << std::endl;
        std::cout << bottom << std::endl;

        std::cout << "\n⏫ Incrementing at Limit\n";
        top.incrementGrade();  // Hata fırlatmalı

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
