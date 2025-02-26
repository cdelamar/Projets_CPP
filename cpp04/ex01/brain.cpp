#include "brain.hpp"

Brain::Brain() {
	std::cout << "cerveau cree" << std::endl;
}

Brain::~Brain() {
	std::cout << "cerveau detruit" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++)
		this->idea[i] = other.idea[i];
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->idea[i] = other.idea[i];
	return *this;
}

std::string Brain::getBrainIdea(int index) {
	if (index < 0 || index >= 100) {
		std::cerr << "Erreur: Index hors limites" << std::endl;
		return "";
	}
	return idea[index];
}

void Brain::setBrainIdea(int index, std::string &newIdea) {
	if (index < 0 || index >= 100) {
		std::cerr << "Erreur: Index hors limites" << std::endl;
		return;
	}
	idea[index] = newIdea;
}

