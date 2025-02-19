#include "DnD.hpp"

Adventurer::Adventurer()
	: name("inconnu"), profession("aventurier"), race("pas de race")
{
	//std::cout << " creation d'un personnage : " << name << std::endl;
}

Adventurer::Adventurer (const Adventurer& other)
{
	std::cout << "Constructeur de recopie" << std::endl;
	this->name = other.name;
	this->profession = other.profession;
	this->race = other.race;
}

Adventurer::~Adventurer()
{
	std::cout << this->name << " has left he party" << std::endl;
}

void Adventurer::announce()
{
	std::cout << "je suis " << name << ", un " << profession << std::endl;
}

Adventurer::Adventurer (std::string name, std::string profession, std::string race)
{
	this->name = name;
	this->profession = profession;
	this->race = race;
	std::cout << "Je suis " << name << ", un " << profession << " " << race << std::endl;
}