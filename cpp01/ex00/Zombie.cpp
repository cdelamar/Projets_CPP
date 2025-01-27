#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << name << " created.\n"; // un print
}

Zombie::~Zombie() { // ca c'est le destructeur, on le vois au tilde
    std::cout << "Zombie " << name << " destroyed.\n"; // on cherche a liberer la memoire allouee dynamiquement
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; // un print
}
