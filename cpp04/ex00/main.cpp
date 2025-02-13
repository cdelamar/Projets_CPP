#include "animal.hpp"
#include "wrongAnimal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main () {

	const Animal* chien = new Dog();
	const Animal* chat = new Cat();
	const WrongAnimal* chatBizarre = new WrongCat();
	const Animal* bestiole = new Animal();


	std::cout << GREEN <<"Type de 'chien' est bien " << chien->getType() << std::endl;
	std::cout <<"Type de 'chat' est bien " << chat->getType() << std::endl;
	std::cout <<"Type de 'bestiole' est bien " << bestiole->getType() << std::endl;
	std::cout <<"Type de 'chatBizarre' est malheureusement " << chatBizarre->getType() << RESET << std::endl;

	bestiole->makeSound();
	chien->makeSound();
	chat->makeSound();
	chatBizarre->makeSound();

    std::cout << "Batterie de tes pas toujours en rapport avec le sujet de l'exo\n" ;

    std::cout << "\n[TEST COPY CONSTRUCTOR]\n";
    Dog originalDog;
    Dog copiedDog(originalDog);
    copiedDog.makeSound();

    std::cout << "\n[TEST ASSIGNMENT OPERATOR]\n";
    Cat firstCat;
    Cat secondCat;
    secondCat = firstCat;
    secondCat.makeSound();

    std::cout << "\n[TEST DESTRUCTION ORDER]\n";
    const Animal* anotherDog = new Dog();
    delete anotherDog;

    std::cout << "\n[TEST WRONG POLYMORPHISM]\n";
    const WrongAnimal* wrongAnimal = new WrongCat();
    wrongAnimal->makeSound(); // appel du makesound de wronganimal
    delete wrongAnimal;

	delete bestiole;
	delete chien;
	delete chat;

	delete chatBizarre;
	return 0;
}