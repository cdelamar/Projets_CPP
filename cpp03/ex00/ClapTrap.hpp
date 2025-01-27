#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cmath>

class ClapTrap {
private:
	std::string Name;
	int Hit;
	int Energy;
	int Attack;

public:
	//coplien
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	//ocnstructeur avec nom
	ClapTrap(const std::string &name);

	//sujet
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif