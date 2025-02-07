#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;

public :

	// COPLIEN
	AForm();
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	// pas coplien mais utile  par rapport au reste
	AForm (const std::string name, const int gradeSign, const int gradeExec);

	//getters
	const std::string	getName() const;
	bool				getSign() const;
	int			getGradeSign() const;
	int			getGradeExec() const;

	//fonction/methode
	void beSigned(const Bureaucrat &bureaucrat);
	// methode virtuelle pure (Classe abstraite)
	virtual void execute(Bureaucrat const & executor) const = 0;

	//Exceptions
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
	class FormUnsignedExeception : public std::exception {
		public:
			const char *what() const throw();
	};

};

//syntactic sugar
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif