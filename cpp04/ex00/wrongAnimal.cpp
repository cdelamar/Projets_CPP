#include "wrongAnimal.hpp"
#include "animal.hpp"

WrongAnimal::WrongAnimal() {
	type = "WrongAnimal";
	std::cout << "**constructeur wrongAnimal**" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "**destructeur wrongAnimal**\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "**copie de wrongAnimal**" << std::endl;

}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		type = other.type;
	std::cout << "**operateur d'affectation WrongAnimal appele**\n";
	return (*this);
}

std::string WrongAnimal::getType() const{
	return(type);
}

void WrongAnimal::makeSound() const{
	std::cout << CYAN <<"Ceci est un son animal bizarre\n" << RESET;
}


WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << MAGENTA << "Voici un chat un peu bizarre\n" << RESET;
}

WrongCat::~WrongCat() {
	std::cout << MAGENTA << "Le chat un peu bizarre s'en va\n" << RESET;
}

WrongCat::WrongCat(WrongCat &other) : WrongAnimal(other) {
	this->type = other.getType();
}

WrongCat &WrongCat::operator=(WrongCat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

std::string WrongCat::getType() const{
	return (type);
}

void WrongCat::makeSound() const {
	std::cout << MAGENTA << "miaulement de chat\n" << RESET;
}
