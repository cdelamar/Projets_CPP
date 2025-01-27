#include "Zombie.hpp"

//stack
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce(); // pas besoin de pointeurs dans la stack
}

