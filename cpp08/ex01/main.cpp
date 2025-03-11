#include <iostream>
#include "Span.hpp"


int main() {
    try {
        std::cout << ">>> TEST DU SUJET" << std::endl;
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;  // 14

        // ➤ Test dépassement de capacité
        std::cout << "\n>>> TEST CAPACITE DEPASSEE" << std::endl;
        try {
            sp.addNumber(42); // Devrait throw
        } catch (const std::exception& e) {
            std::cerr << "Erreur attendue : " << e.what() << std::endl;
        }

        // ➤ Test SANS AUCUNE VALEUR
        std::cout << "\n>>> TEST SANS AUCUNE VALEUR" << std::endl;
        Span sp_empty(5);
        try {
            sp_empty.shortestSpan(); // Doit throw
        } catch (const std::exception& e) {
            std::cerr << "Erreur attendue (shortestSpan): " << e.what() << std::endl;
        }
        try {
            sp_empty.longestSpan(); // Doit throw
        } catch (const std::exception& e) {
            std::cerr << "Erreur attendue (longestSpan): " << e.what() << std::endl;
        }

        // ➤ Test AVEC UN SEUL NOMBRE
        std::cout << "\n>>> TEST AVEC UN SEUL NOMBRE" << std::endl;
        Span sp_single(5);
        sp_single.addNumber(42);
        try {
            sp_single.shortestSpan(); // Doit throw
        } catch (const std::exception& e) {
            std::cerr << "Erreur attendue (shortestSpan): " << e.what() << std::endl;
        }
        try {
            sp_single.longestSpan(); // Doit throw
        } catch (const std::exception& e) {
            std::cerr << "Erreur attendue (longestSpan): " << e.what() << std::endl;
        }

        // ➤ Test GROS VOLUME
        std::cout << "\n>>> TEST GROS VOLUME" << std::endl;
        Span sp3(10000);
        for (int i = 0; i < 10000; ++i)
            sp3.addNumber(i * 2);
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp3.longestSpan() << std::endl;

        // ➤ Test PLAGE D'ITERATEURS
        std::cout << "\n>>> TEST PLAGE ITERATEURS" << std::endl;
        std::vector<int> batch;
        for (int i = 100; i < 110; ++i)
            batch.push_back(i);

        Span sp4(10);
        sp4.addNumber(batch.begin(), batch.end());
        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp4.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    return 0;
}