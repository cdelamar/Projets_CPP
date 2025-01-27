#include "ClapTrap.hpp"

int main () {
	ClapTrap claptrap01("jean-louis");
	ClapTrap claptrap02("jean-luc");
	//ClapTrap

	claptrap01.attack("jean-luc");
	claptrap02.takeDamage(3);
	claptrap02.beRepaired(7);

	claptrap01.attack("jean-luc");
	claptrap02.takeDamage(9);

	claptrap01.attack("jean-luc");
	claptrap02.takeDamage(9);

	/*
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");
	claptrap01.attack("jean-luc");

	//02 prend des dgt
	//02 se repare
	*/
	return 0;
}