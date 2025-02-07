#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>   // ✅ Permet d'afficher du texte avec std::cout, std::cerr
#include <fstream>    // ✅ Utilisé dans ShrubberyCreationForm pour manipuler des fichiers
#include <string>     // ✅ Gère les std::string (noms, messages d'erreur, etc.)
#include <exception>  // ✅ Contient la classe std::exception, utilisée pour les exceptions personnalisées
#include <stdexcept>  // ✅ Fournit des exceptions standard comme std::runtime_error
#include <cstdlib>    // ✅ Contient rand() et srand(), utilisés pour RobotomyRequestForm
#include "AForm.hpp"


class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int 		_grade;

public:
	//coplien
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);

	//getters
	int getGrade() const;
	std::string getName() const;

	//if throw()
	void upGrade();
	void downGrade();

	//fonctions
	void signForm(AForm &form);
	void executeForm(AForm const & form);

	//exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

//syntactic sugar
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif