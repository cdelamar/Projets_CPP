#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> // Pour std::fixed et std::setprecision



// catgpt() {
//     for file in "$@"; do
//         if [[ -f "$file" ]]; then
//             echo "=== $file ==="
//             grep -v '^/\*.*\*/$' "$file"
//         else
//             echo "=== $file ==="
//             echo "Fichier non trouvé ou n'est pas un fichier régulier."
//         fi
//     done
// }


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input file>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");

        std::ifstream inputFile(argv[1]);
        if (!inputFile.is_open()) {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        std::string line;
        std::getline(inputFile, line); // Optionnel, saute le header si présent

        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string date, separator, valueStr;

            // Ex : 2011-01-03 | 3
            if (!std::getline(iss, date, ' ') ||
                !std::getline(iss, separator, ' ') ||
                !std::getline(iss, valueStr)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            if (separator != "|") {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            // Validation de la date
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            // Validation de la valeur
            float value;
            if (!isValidValue(valueStr, value)) {
                std::cerr << "Error: bad input => " << valueStr << std::endl;
                continue;
            }

            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            try {
                float rate = btc.getRateForDate(date);
                float result = rate * value;

                // Affichage avec précision propre
                std::cout << date << " => " << value
                          << " = " << std::fixed << std::setprecision(2)
                          << result << std::endl;

            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }

        inputFile.close();

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
