#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	Intern intern;
	AForm *form;

	struct Test {
		const char *nameForm;
		const char *target;
	};

	const Test tabTest[] = {
        { "shrubbery creation", "Garden" },
        { "robotomy request", "Bender" },
        { "presidential pardon", "Zaphod" },
        { "invalid form", "Problems" } // erreur ici
	};

	for (int i = 0; i < 4; i++) {
        std::cout << "\nTrying to create: " << tabTest[i].nameForm << " for " << tabTest[i].target << std::endl;
        form = intern.makeForm(tabTest[i].nameForm, tabTest[i].target);

        if (form)
		{
            std::cout << "Form " << form->getName() << " successfully created\n";
            delete form;
        }

		else
            std::cout << "Failed to create form: " << tabTest[i].nameForm << "\n";
    }
}
