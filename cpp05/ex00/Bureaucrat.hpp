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