#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon; // this pour "dans l"
}

void HumanB::attack() {
    if (weapon) {
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon" << std::endl;
    }
}
