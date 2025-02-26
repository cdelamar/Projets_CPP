#include "dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	brain = new Brain();
	std::cout << BLUE << "Voici un chien\n" << RESET;
}

Dog::~Dog() {
	delete brain;
	std::cout << BLUE << "Le chien s'en va\n" << RESET;
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->type = other.type;
	this->brain = new Brain(*other.brain); // Deep copy ici, bien

}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = (other.brain) ? new Brain(*other.brain) : NULL;
	} //ternaire pour eviter le crash si le brain copie est vide (aussi pour pratiquer un peu le ternaire)
	std::cout << "Opérateur d'affectation Dog appelé" << std::endl;
	return *this;
}

std::string Dog::getType() const{
	return (type);
}

void Dog::makeSound() const {
	std::cout << BLUE << "ouaf ouaf je suis le chieeeng !\n" << RESET;
}

void Dog::setBrainIdea(int index, std::string idea) {
    brain->setBrainIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getBrainIdea(index);
}