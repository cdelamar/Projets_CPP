#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "A zombie has been created!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
