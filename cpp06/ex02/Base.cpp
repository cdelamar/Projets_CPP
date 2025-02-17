#include "Base.hpp"


Base::~Base() { std::cout << "Base destroyed" << std::endl ;}

// on cherche a generer (instancier pour les nerds) une classe de facon random
// > rand A, B ou C
// > on lance un De 6 faces
// > 1 - 2 c'est A
// > 3 - 4 c'est B
// > 5 - 6 c'est C

Base *makeA() {return new A();} // 'new' car pointeur
Base *makeB() {return new B();}
Base *makeC() {return new C();}
// je cree ces ptites fonctions ici pour le tableau de pointeurs sur fonctions.
// plus scalable qu'un if/else, mais pas forcement necessaire sur un ptit exo
// comme celui ci, c'est juste pour pratiquer le concept !


Base *generate(void)
{
	int dice = rand() % 6;
	Base * (*diceTab[])() = { makeA, makeA, makeB, makeB, makeC, makeC };	// ici, les 6 faces de notre D6
	// syntaxe un peu compliqued
	// ici, '(**diceTab)' retournera une erreur a la compilation,
	// car il considere que c'est un pointeur sur une unique fonction.
	// pas le choix, il faut les crochets;
	// ! : on oublie pas les parentheses en car tableaux de FONCTIONS


	return diceTab[dice]();
}


void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {} // on passe a la suite

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (...) {
		std::cout << "Message d'erreur pour l'examinateur qui voudrais faire planter mon programme" << std::endl;
	}
}

