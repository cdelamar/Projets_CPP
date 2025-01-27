#include "Zombie.hpp"

//heap
Zombie* newZombie(std::string name)
{
    return new Zombie(name); // new : c'est la nouveaute de cet exo avec le tilde ~, un genre de malloc
}

/*
Différences entre Heap et Stack
Caractéristique	:			Heap (newZombie)							Stack (randomChump)
Durée de vie	:			Persiste jusqu'à delete.					Automatiquement détruit à la fin de la portée.
Gestion mémoire	:			Manuelle (new et delete).					Automatique. Pas besoin de delete.
Performance		:			Plus lent (allocation dynamique).			Plus rapide (allocation locale).
Utilisation typique	:		Objets qui doivent vivre longtemps.			Objets temporaires ou locaux.
*/