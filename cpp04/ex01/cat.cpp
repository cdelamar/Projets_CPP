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
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = (other.brain) ? new Brain(*other.brain) : NULL;
	} //ternaire pour eviter le crash si le brain copie est vide (aussi pour pratiquer un peu le ternaire)
	std::cout << "Opérateur d'affectation Cat appelé" << std::endl;
	return *this;
}

std::string Cat::getType() const{
	return (type);
}

void Cat::makeSound() const {
	std::cout << RED << "miaou. effectivement, c'est bien moi, le chat\n" << RESET;
}

void Cat::setBrainIdea(int index, std::string idea) {
    brain->setBrainIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
    return brain->getBrainIdea(index);
}