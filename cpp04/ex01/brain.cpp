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


