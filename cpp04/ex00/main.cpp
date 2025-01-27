#include "animal.hpp"
#include "wrongAnimal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main () {

	const Animal* chien = new Dog();
	const Animal* chat = new Cat();
	const WrongAnimal* chatBizarre = new WrongCat();
	const Animal* bestiole = new Animal();


	std::cout <<"Type de 'chien' ->		" << chien->getType() << std::endl;
	std::cout <<"Type de 'chat' ->		" << chat->getType() << std::endl;
	std::cout <<"Type de 'bestiole' ->	" << bestiole->getType() << std::endl;
	std::cout <<"Type de 'chatBizarre' -> " << chatBizarre->getType() << std::endl;

	bestiole->makeSound();
	chien->makeSound();
	chat->makeSound();
	chatBizarre->makeSound();

	delete bestiole;
	delete chien;
	delete chat;

	delete chatBizarre;
	return 0;
}