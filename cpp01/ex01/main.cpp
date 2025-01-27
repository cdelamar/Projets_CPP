#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {

	int numZombies = 12; // Nombre de zombies dans la horde
    Zombie* horde = zombieHorde(numZombies, "Zombie");

    if (horde != NULL)
	{
        int i = 0;
        while (i < numZombies)
		{
            horde[i].announce(); // zombie [i] annonce son nom
            i++;
        }

        delete[] horde; // free()
    }

    return 0;
}
