#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << _name << ": hello, my grade is "<< _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << ": destroyed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << _name << ": (COPY) hello, new grade here : " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << _name << ": operateur de copie\n";
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();

	std::cout << _name << ": hello, my grade is "<< _grade << std::endl;
 }

int Bureaucrat::getGrade() const {
	return (_grade);
}

std::string Bureaucrat::getName() const {
	return (_name);
}

void Bureaucrat::upGrade()
{
	if(_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::downGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}