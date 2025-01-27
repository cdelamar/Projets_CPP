#include "Fixed.hpp"

/*
int main(void) {
    Fixed a;            // Appelle le constructeur par défaut
    Fixed b(a);         // Appelle le constructeur de recopie
    Fixed c;

    c = a;              // Appelle l'opérateur d'affectation

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
*/


int main(void) {
    Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

    std::cout << "Initial value of a: " << a.getRawBits() << std::endl;

    a.setRawBits(42);  // Changer la valeur brute stockée
    std::cout << "Updated value of a: " << a.getRawBits() << std::endl;
    std::cout << "Updated value of B: " << b.getRawBits() << std::endl;
    std::cout << "Updated value of C: " << c.getRawBits() << std::endl;

    a.setRawBits(1024);  // Essayer avec une autre valeur
    b.setRawBits(999);  // Essayer avec une autre valeur
    c.setRawBits(1418);  // Essayer avec une autre valeur
    std::cout << "Updated value of BBB: " << b.getRawBits() << std::endl;
	std::cout << "Updated value of a: " << a.getRawBits() << std::endl;
    std::cout << "Updated value of C: " << c.getRawBits() << std::endl;

    return 0;
}