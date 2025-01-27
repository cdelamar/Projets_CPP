#ifndef DND_HPP
#define DND_HPP

#include <iostream>
#include <string>

class Character {
private :
	std::string name;
	std::string profession;
	std::string race;
public : //coplien

	Character (); //constrcuteur
	Character (const Character& other); //recopie
	Character operator=(const Character& other); // operateur d'affectation
	~Character (); // destruct

	Character (std::string name, std::string profession, std::string race);

	void announce();
};

#endif