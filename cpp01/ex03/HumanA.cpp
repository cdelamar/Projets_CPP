#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : name(name), weapon(Weapon) {}

void HumanA::attack() {
	std::cout << name << " attack with " << weapon.getType() << std::endl;
}

