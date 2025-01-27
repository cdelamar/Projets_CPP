#include "ClapTrap.hpp"

//constructeur
ClapTrap::ClapTrap()
	: Name("Claptrap"), Hit(10), Energy(10), Attack(0)  {
	std::cout << this->Name << " apparait." << std::endl;
}

//destructeur
ClapTrap::~ClapTrap() {
	std::cout << this->Name << " s'en va, la bise !" << std::endl;
}

//constructeur recopie
ClapTrap::ClapTrap (const ClapTrap &other) {
	*this = other;
	std::cout << "Voici un autre cl4p-tr4p : " << Name << std::endl;
}

// operateur d'affectation
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->Name = other.Name;
		this->Hit = other.Hit;
		this->Energy = other.Energy;
		this->Attack = other.Attack;
	}
	// message pour assigner
	return *this;
}

// Coplien au dessus
//____________________

// pour pouvoir declarer son nom dans le main
ClapTrap::ClapTrap(const std::string &name)
	: Name(name), Hit(10), Energy(10), Attack(0)  {
	std::cout << this->Name << " apparait." << std::endl;
}

// Sujet
//--------------

void ClapTrap::attack(const std::string& target) {
	if (this->Energy <= 0)
	{
		std::cout << Name << " n'a plus d'energie !" << std::endl;
		return ;
	}
	else if (this->Hit <= 0)
	{
		std::cout << Name << " est HS, il ne peut pas attaquer !" << std::endl;
		return ;
	}
	else
	{
		this->Energy--;
		std::cout << this->Name << " attaque " << target
				<< ", ce qui cause " << Attack << " points de degats."
				<< std::endl;

		return ;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (this->Hit <= 0)
	{
		std::cout << this->Name << " est deja mort !" << std::endl;
		return ;
	}

	else
	{
		Hit = Hit - amount;
		std::cout << this->Name << " subit " << amount << " de degats !" << std::endl;
		if (this->Hit <= 0)
			std::cout << this->Name << " est mort !" << std::endl;
		return ;
	}
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (Energy <= 0) {
        std::cout << Name << " ne peut pas se reparer, energie insuffisante !" << std::endl;
        return;
    }
    if (Hit <= 0) {
        std::cout << Name << " est deja mort, il ne peut pas se reparer !" << std::endl;
        return;
    }
    Energy--;
    Hit += amount;
    std::cout << Name << " se repare de " << amount << " points de vie. "
              << "Il a maintenant " << Hit << " points de vie." << std::endl;
}
