#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	Hit = 100;
	Energy = 50;
	Attack = 20;
	std::cout << "Scav par defaut cree !" << std::endl;
}

//constr recopie
ScavTrap::ScavTrap (const ScavTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap " << Name << " copie" << std::endl;
}

//operateur aeffectation
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap " << Name << "assigne via operateur d'affectation" << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	Hit = 100;
	Energy = 50;
	Attack = 20;
	std::cout << "ScavTrap " << name << " est la !" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << Name << " passe en mode Gate-Keeper" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "scavtrap " << Name << " Disparait dans la brume" << std::endl;
}