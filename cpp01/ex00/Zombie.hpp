#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name); // Constructeur
    ~Zombie(); // Destructeur

    void announce(); // Annonce du zombie
};

// est ce que j'ai le droit de mettre mes fonctioons dans ce header ?
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif


