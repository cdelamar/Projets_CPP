#include <iostream>

int main() {
	// 1. la chaine de base
	std::string brain = "HI THIS IS BRAIN";

	// 2. pointeur sur chainne
	std::string *stringPTR = &brain;

	// 3. Reference de chaine (tricky)
	std::string &stringREF = brain;

	// adresses mémoire
	std::cout << "Address string brain: " << &brain << std::endl;
	std::cout << "Address stringPTR: " << stringPTR << std::endl;
	std::cout << "Address stringREF: " << &stringREF << std::endl;

	// valeurs
	std::cout << "Value string brain: " << brain << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value REFERED by stringREF: " << stringREF << std::endl;

	return 0;
}
