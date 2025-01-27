#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
	{
        std::cout << "Invalid number of zombies!" << std::endl;
        return (NULL);
    }

    Zombie* horde = new Zombie[N]; // new par zombies
    int i = 0;

	while (i < N)
	{
        std::stringstream nameBuilder;
        nameBuilder << name << "_" << (i + 1); // construit le nom (Zombie_1, Zombie_2, ...)
        horde[i].setName(nameBuilder.str());  // attribu le nom au zombie
        i++;
    }

    return(horde);
}

