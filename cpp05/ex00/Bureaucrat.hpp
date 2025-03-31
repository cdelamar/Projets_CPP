#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

class Bureaucrat {
private:
	const std::string _name;
	int 		_grade;

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);

	int getGrade() const;
	std::string getName() const;

	void upGrade();
	void downGrade();

	//std::exception contient une methode en polymorphisme dynamique
	// ca veut dire que tout l'interet et de redefinir le message
	// qu'on envoie avec

	class GradeTooHighException : public std::exception
	{
		// what() : c'est le message qu'on implemente
		// throw() : ici, throw() est vide, et nous informe donc
		// qu'il ne lancera pas d'exception apres
		// ALTERNATIVE post C++98 : noexcept

		//pourquoi mettre throw() vide ?
		//pour garantir qu'aucune exception ne sera levees apres what()
		//LE CODE FONCTIONNE MEME SANS THROW()
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