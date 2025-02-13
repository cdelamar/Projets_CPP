#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"

int main () {

	const Animal* chien = new Dog();
	const Animal* chat = new Cat();
	const Animal* bestiole = new Animal();


	std::cout <<"Type de 'chien' ->		" << chien->getType() << std::endl;
	std::cout <<"Type de 'chat' ->		" << chat->getType() << std::endl;
	std::cout <<"Type de 'bestiole' ->	" << bestiole->getType() << std::endl;

	bestiole->makeSound();
	chien->makeSound();
	chat->makeSound();

	delete bestiole;
	delete chien;
	delete chat;

	return 0;
}