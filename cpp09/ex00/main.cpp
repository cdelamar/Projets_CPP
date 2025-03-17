#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <filename>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    exchange.loadCsv("data.csv"); // la base des taux
    exchange.processInput(argv[1]); // l'argv1

    return 0;
}