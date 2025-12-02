#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
    // 1. Argüman kontrolü
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        // 2. Nesneyi oluştur (Constructor Date.csv'yi okur)
        BitcoinExchange btc;

        // 3. Input dosyasını işle
        btc.run(argv[1]);

    } catch (const std::exception &e) {
        // Constructor'da dosya açılmazsa buraya düşer
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}