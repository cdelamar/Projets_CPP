#include "dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << BLUE << "Voici un chien\n" << RESET;
}

Dog::~Dog() {
	std::cout << BLUE << "Le chien s'en va\n" << RESET;
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

std::string Dog::getType() const{
	return (type);
}

void Dog::makeSound() const {
	std::cout << BLUE << "ouaf ouaf je suis le chieeeng !\n" << RESET;
}
