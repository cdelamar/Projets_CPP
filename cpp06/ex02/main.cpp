#include "Base.hpp"

int main ()
{
	srand(time(NULL)); 	// comme dans philo, on init un generateur de nb random
						// sans srand, le lancer de D6 demarre toujours sur la meme seed (rien a voir avec minecraft)

	std::cout << "On lance le Dé..." << std::endl;
	Base* test = generate();

	//Base* test2 = NULL;

    std::cout << "Identification par pointeur : ";
    identify(test);

    std::cout << "Identification par ref : ";
    identify(*test);


/*

    std::cout << "\n--- difference static_cast vs dynamic_cast ---" << std::endl;

	Base* fakeBase = new C();

    // STATIC_CAST : compile et "passe", mais risque
    B* forcedB = static_cast<B*>(fakeBase); // pas de warning
    std::cout << "static_cast<Base* -> B*>: " << forcedB << std::endl;

    // DYNAMIC_CAST : retourne NULL si pas bon
    B* checkedB = dynamic_cast<B*>(fakeBase);
    if (checkedB)
        std::cout << "dynamic_cast<Base* -> B*>: " << checkedB << " ✅ cast réussi" << std::endl;
    else
        std::cout << "dynamic_cast<Base* -> B*>: NULL ❌ cast refusé" << std::endl;

    delete fakeBase;
*/
	delete test;
	return 0;


}