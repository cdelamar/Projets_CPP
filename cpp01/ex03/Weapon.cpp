#include "Weapon.hpp"

// construceur, vide car juste besoin pour init
Weapon::Weapon(std::string type) : type(type) {}

// Retourne le type de l'arme, synthaxe degueulasse wow
std::string Weapon::getType() {
    return type;
}

// Change le type de l'arme
void Weapon::setType(std::string newType) {
    type = newType;
}
