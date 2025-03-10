#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		std::cout << ">>> TEST BASIQUE" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;  // 14

		// Tester l'exception si on dépasse la capacité
		std::cout << "\n>>> TEST DE CAPACITE DEPASSEE" << std::endl;
		try {
			sp.addNumber(42);  // Doit throw
		} catch (const std::exception& e) {
			std::cerr << "Erreur attendue : " << e.what() << std::endl;
		}

		// Tester l'exception si pas assez de nombres
		std::cout << "\n>>> TEST SANS ASSEZ DE NOMBRES" << std::endl;
		Span sp2(1);
		sp2.addNumber(1);
		try {
			sp2.shortestSpan();  // Doit throw
		} catch (const std::exception& e) {
			std::cerr << "Erreur attendue : " << e.what() << std::endl;
		}

		// Tester avec beaucoup de valeurs
		std::cout << "\n>>> TEST GROS VOLUME" << std::endl;
		Span sp3(10000);
		for (int i = 0; i < 10000; ++i)
			sp3.addNumber(i * 2);  // Pairs pour un span min de 2

		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl; // 2
		std::cout << "Longest span : " << sp3.longestSpan() << std::endl;  // (max - min)

		// Bonus : tester avec un seul nombre répété
		std::cout << "\n>>> TEST AVEC VALEURS IDENTIQUES" << std::endl;
		Span sp4(5);
		for (int i = 0; i < 5; ++i)
			sp4.addNumber(42);

		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl; // 0
		std::cout << "Longest span : " << sp4.longestSpan() << std::endl;  // 0
	}
	catch (const std::exception& e)
	{
		std::cerr << "Erreur inattendue : " << e.what() << std::endl;
	}
	return 0;
}
