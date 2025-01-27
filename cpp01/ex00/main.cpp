#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("Jean-philippe de la heap");
    heapZombie->announce();
    delete heapZombie; // un peu a la malloc() free() mais avec une synthaxe occulte

    randomChump("Jean-jacques de la stack");
	// pas besoin de delete stackZombie iltermine tout seul
    return 0;
}
