#include "animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "**constructeur d'animal**" << std::endl;
}

Animal::~Animal() {
	std::cout << "**destructeur d'animal**\n";
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "**copie de animal**" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		type = other.type;
	std::cout << "**operateur d'affectation Animal appele**\n";
	return (*this);
}

std::string Animal::getType() const{
	return(type);
}

void Animal::makeSound() const{
	std::cout << YELLOW <<"bruit d'animal random\n" << RESET;
}