#include "DnD.hpp"

Character::Character()
	: name("inconnu"), profession("aventurier"), race("pas de race")
{
	//std::cout << " creation d'un personnage : " << name << std::endl;
}

Character::Character (const Character& other)
{
	std::cout << "Constructeur de recopie" << std::endl;
	this->name = other.name;
	this->profession = other.profession;
	this->race = other.race;
}

Character::~Character()
{
	std::cout << this->name << " has left he party" << std::endl;
}

void Character::announce()
{
	std::cout << "je suis " << name << ", un " << profession << std::endl;
}

Character::Character (std::string name, std::string profession, std::string race)
{
	this->name = name;
	this->profession = profession;
	this->race = race;
	std::cout << "Je suis " << name << ", un " << profession << " " << race << std::endl;
}