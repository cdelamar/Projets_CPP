#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Creating Intern\n";
}

Intern::~Intern() {
	std::cout << "Destroying Intern\n";
}

Intern::Intern (const Intern &other) {
	(void)other; // Intern n'a rien, cette fonction sert pas a grand chose
	std::cout << "Copied Intern\n";
}

Intern &Intern::operator=(const Intern &other) {
	(void)other; // toujours rien
	std::cout << "Intern copied\n";
	return (*this);
}


// Fonction pour le LUT (static marche comme en C)

static AForm *createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target) ;
}
static AForm *createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target) ;
}
static AForm *createPardon(const std::string &target) {
	return new PresidentialPardonForm(target) ;
}

// creation du LUT dans makeForm

struct formEntry {
	const std::string _name; // ex : "shrubbery creation"
	AForm* (*creator)(const std::string &target); // ex : &createShrubbery
};

AForm *Intern::makeForm(const std::string &nameForm, const std::string &target) const {
	formEntry formTab[] = {
		{ "shrubbery creation", &createShrubbery},
		{ "robotomy request", &createRobotomy},
		{ "presidential pardon", &createPardon}
	};

	for (int i = 0; i < 3; i++) {
		if (nameForm == formTab[i]._name) {
			std::cout << "Intern create " << nameForm << std::endl;
			return formTab[i].creator(target);
		}
	}

	std::cout << "Error: Form type " << nameForm << " doesn't match" << std::endl;
	return NULL;
}

