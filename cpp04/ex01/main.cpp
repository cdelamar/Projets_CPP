#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "brain.hpp"

int main() {
    const int numAnimals = 4; // 2 chiens, 2 chats
    Animal* animals[numAnimals];

    std::cout << "\n--- CREATION DES ANIMAUX ---\n" << std::endl;

    // Création des animaux
    for (int i = 0; i < numAnimals; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- AJOUT D'IDEES SPECIFIQUES ---\n" << std::endl;

    // Attribution de 4 idées différentes par animal
    std::string dogIdeas[4] = {"J'adore courir", "Je veux un os", "Qui est un bon chien ?", "Dormir sur le canapé"};
    std::string catIdeas[4] = {"Manger du poisson", "Je suis le maître de la maison", "Attraper une souris", "Dormir au soleil"};

    for (int i = 0; i < numAnimals; i++) {
        if (Dog* d = dynamic_cast<Dog*>(animals[i])) {
            for (int j = 0; j < 4; j++) {
                d->setBrainIdea(j, dogIdeas[j]);
            }
        } else if (Cat* c = dynamic_cast<Cat*>(animals[i])) {
            for (int j = 0; j < 4; j++) {
                c->setBrainIdea(j, catIdeas[j]);
            }
        }
    }

    std::cout << "\n--- VERIFICATION DES IDEES ---\n" << std::endl;

    // Affichage des idées originales
    for (int i = 0; i < numAnimals; i++) {
        if (Dog* d = dynamic_cast<Dog*>(animals[i])) {
            std::cout << "Chien " << i << " idées:" << std::endl;
            for (int j = 0; j < 4; j++) {
                std::cout << "- " << d->getBrainIdea(j) << std::endl;
            }
        } else if (Cat* c = dynamic_cast<Cat*>(animals[i])) {
            std::cout << "Chat " << i << " idées:" << std::endl;
            for (int j = 0; j < 4; j++) {
                std::cout << "- " << c->getBrainIdea(j) << std::endl;
            }
        }
        std::cout << std::endl;
    }

    std::cout << "\n--- TEST DE COPIE PROFONDE ---\n" << std::endl;

    // Copie d'un animal pour tester la copie profonde
    Dog originalDog;
    originalDog.setBrainIdea(0, "Je veux une balle !");
    originalDog.setBrainIdea(1, "J'aime nager !");
    originalDog.setBrainIdea(2, "Je protège ma maison !");
    originalDog.setBrainIdea(3, "J'adore creuser !");

    std::cout << "Idées du chien original avant copie:" << std::endl;
    for (int j = 0; j < 4; j++) {
        std::cout << "- " << originalDog.getBrainIdea(j) << std::endl;
    }

    Dog copiedDog = originalDog;

    std::cout << "\nIdées du chien copié après copie profonde:" << std::endl;
    for (int j = 0; j < 4; j++) {
        std::cout << "- " << copiedDog.getBrainIdea(j) << std::endl;
    }

    std::cout << "\n--- MODIFICATION DES IDEES POUR VERIFIER L'INDEPENDANCE ---\n" << std::endl;
    
    copiedDog.setBrainIdea(0, "Je suis un chien cloné !");
    
    std::cout << "Nouvelle idée du chien copié (index 0): " << copiedDog.getBrainIdea(0) << std::endl;
    std::cout << "Idée du chien original (index 0) : " << originalDog.getBrainIdea(0) << std::endl;

    std::cout << "\n--- SUPPRESSION DU TABLEAU D'ANIMAUX ---\n" << std::endl;

    // Suppression des objets pour éviter les fuites mémoire
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }

    return 0;
}
