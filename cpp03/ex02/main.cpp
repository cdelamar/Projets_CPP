#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main () {
	ClapTrap claptrap01("jean-louis");
	ClapTrap claptrap02("jean-luc");
	ScavTrap scav("N3D_K3LLY");
	scav.guardGate();
	FragTrap test01("robochiotte");

	return 0;
}