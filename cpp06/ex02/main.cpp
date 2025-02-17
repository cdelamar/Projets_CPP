#include "Base.hpp"

int main ()
{
	srand(time(NULL)); 	// comme dans philo, on init un generateur de nb random
						// sans srand, le lancer de D6 demarre toujours sur la meme seed (rien a voir avec minecraft)

	std::cout << "On lance le Dé..." << std::endl;
	Base* test = generate();

    std::cout << "Identification par pointeur : ";
    identify(test);

    std::cout << "Identification par ref : ";
    identify(*test);

	delete test;
	return 0;
}