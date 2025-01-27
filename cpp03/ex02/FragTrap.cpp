#include "FragTrap.hpp"

FragTrap::FragTrap() :ClapTrap("DefaultFragTrap") {
	Hit = 100;
	Energy = 100;
	Attack = 100;
	std::cout << GREEN << "The FragTrap " << Name << " is created !" << RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << GREEN << "FragTrap " << Name << " is no more" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	// *this = other;
	std::cout << GREEN << "Creasting a copy of FragTrap " << Name << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
			ClapTrap::operator=(other);
	std::cout << GREEN << "FragTrap " << Name << " made through 'operator=' affectaion" << RESET << std::endl;
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	Hit = 100;
	Energy = 100;
	Attack = 100;
	std::cout << GREEN << "The FragTrap " << Name << " is created !" << RESET << std::endl;
}

void FragTrap::highFiveGuys() {
	std::cout << GREEN << Name << " : High five ! 🙌 🙌 🙌 🙌 🙌" << RESET << std::endl;
}