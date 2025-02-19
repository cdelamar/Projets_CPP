#ifndef DND_HPP
#define DND_HPP

#include <iostream>
#include <string>

class Adventurer {
private :
	std::string name;
	std::string profession;
	std::string race;
public : //coplien

	Adventurer (); //constrcuteur
	Adventurer (const Adventurer& other); //recopie
	Adventurer operator=(const Adventurer& other); // operateur d'affectation
	~Adventurer (); // destruct

	Adventurer (std::string name, std::string profession, std::string race);

	void announce();
};

#endif