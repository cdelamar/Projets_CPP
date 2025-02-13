#include "cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << RED << "Voici un chat\n" << RESET;
}

Cat::~Cat() {
	std::cout << RED << "Le chat retourne dans sa litiere\n" << RESET;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

std::string Cat::getType() const{
	return (type);
}

void Cat::makeSound() const {
	std::cout << RED << "miaou. effectivement, c'est bien moi, le chat\n" << RESET;
}
