#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Form.hpp"


class Form; // il herite pas mais fdaut le mettre dans le header

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
	void signForm(Form &form);

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