#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string	_name;
	bool				_isSigned; // not at construct
	const int			_gradeSign;
	const int			_gradeExec;

public :

	// COPLIEN
	Form();
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	Form (const std::string name, const int gradeSign, const int gradeExec);

	//getters
	const std::string	getName() const;
	bool				getSign() const;
	int			getGradeSign() const;
	int			getGradeExec() const;

	//fonction/methode
	void beSigned(const Bureaucrat &bureaucrat);

	//Exceptions
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

};

//syntactic sugar
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif