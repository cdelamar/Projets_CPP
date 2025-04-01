#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
		_____ DISCLAIMER _____

	A partir de cet exercice,
	j'incorpore l'option 'make hardcore'
	afin d'inciter les bonnes pratiques du C++.
	(en plus de -Wall, -Wextra et -Werror, connus depuis la piscine)

	Les Flags:

	🚨 Sécurité et Qualité du Code 🚨

	-Wshadow           : Avertit si une variable masque une autre (évite les erreurs de visibilité).
	-Wold-style-cast   : Empêche l'utilisation des casts en style C (oblige les `static_cast<>` en C++).
	-Woverloaded-virtual : Alerte si une méthode virtuelle est cachée par une surcharge accidentelle.
	-Wpedantic         : Rend la compilation plus stricte en appliquant rigoureusement la norme C++98.
	-Weffc++           : Applique les recommandations du livre "Effective C++" de Scott Meyers.

	🔢 Gestion des Conversions Numériques 🔢

	-Wconversion       : Alerte sur les conversions implicites pouvant entraîner des pertes de précision.
	-Wsign-conversion  : Détecte les conversions implicites entre `signed` et `unsigned` (source de bugs).

	🛠 Optimisation et Performance 🛠

	-O2               : Optimisation agressive du code pour de meilleures performances.
	-march=native     : Optimise le code pour l'architecture CPU locale.
	-mtune=native     : Ajuste la compilation pour optimiser l’exécution sur la machine cible.
	-fstrict-aliasing : Active les optimisations basées sur l’aliasing mémoire.
	-flto             : Active la Link-Time Optimization (LTO) pour réduire la taille et accélérer le binaire.

	🔍 Debugging et Détection de Comportements Indéfinis 🔍

	-g3                    	: Génère un maximum d'informations de debug pour `gdb`.
	-fno-omit-frame-pointer : Empêche l'optimisation du frame pointer (utile pour le debugging).
	-DDEBUG          		: Définit un flag de préprocesseur `DEBUG` permettant d’activer des logs spécifiques.

	Comment l'utiliser ?
	- compiler avec 'make hardcore'
	- executer ./Bureaucrat_hardcore
	- flags de bases toujours accessibles via './Bureaucrat'
*/

void testFormExec(Bureaucrat &bureaucrat, AForm &form)
{
	try
	{
		std::cout << bureaucrat << "try to Exec form " << form << std::endl;
		bureaucrat.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

int main() {
	try {
		Bureaucrat BigBoss("Big Boss", 1);
		Bureaucrat Manager("Manager", 60);
		Bureaucrat Salarie("Salarie Random", 120);
		Bureaucrat Stagiaire("Billy le Stagiaire", 150);

		// std::cout << BigBoss << std::endl;
		// std::cout << Manager << std::endl;
		// std::cout << Salarie << std::endl;
		// std::cout << Stagiaire << std::endl;

		std::cout << BLUE <<"\n---- Creation des formulaires ----\n" << std::endl << RESET;

		ShrubberyCreationForm   shrub("bonjour_je_test");
		RobotomyRequestForm     robot("Robotomy");
		PresidentialPardonForm  pardon("Pardon");

		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		std::cout << BLUE <<"\n---- Tentatives de signature REUSSIES ----\n" << std::endl << RESET;

		BigBoss.signForm(shrub);
		BigBoss.signForm(pardon);
		BigBoss.signForm(robot);
		Manager.signForm(shrub);
		Manager.signForm(robot);


		std::cout << BLUE <<"\n---- Tentatives de signature ECHOUEES ----\n" << std::endl << RESET;

		Manager.signForm(pardon);
		Stagiaire.signForm(shrub);
		Stagiaire.signForm(pardon);
		Stagiaire.signForm(robot);

		std::cout << BLUE <<"\n---- Tentatives d'execution REUSSIES ----\n" << std::endl << RESET;

		testFormExec(BigBoss, shrub);
		testFormExec(BigBoss, pardon);
		testFormExec(BigBoss, robot);
		testFormExec(Manager, shrub);
		testFormExec(Manager, robot);

		std::cout << BLUE <<"\n---- Tentatives d'execution ECHOUEES ----\n" << std::endl << RESET;

		testFormExec(Manager, pardon);
		testFormExec(Stagiaire, shrub);
		testFormExec(Stagiaire, pardon);
		testFormExec(Stagiaire, robot);

	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
