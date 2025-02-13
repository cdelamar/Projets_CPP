#include "cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain();
	std::cout << RED << "Voici un chat\n" << RESET;
}

Cat::~Cat() {
	delete brain;
	std::cout << RED << "Le chat retourne dans sa litiere\n" << RESET;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->type = other.type;
	this->brain = new Brain(*other.brain); // Deep copy ici, bien
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		type = other.type;
	
	delete this->brain; //safe
	this->brain = new Brain(*other.brain); //la aussi deep copy
	return *this;
}

std::string Cat::getType() const{
	return (type);
}

void Cat::makeSound() const {
	std::cout << RED << "miaou. effectivement, c'est bien moi, le chat\n" << RESET;
}
