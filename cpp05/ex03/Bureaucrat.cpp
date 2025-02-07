#include "Bureaucrat.hpp"

// COPLIEN

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << YELLOW << _name << ": hello, my grade is "<< _grade << RESET  << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << ": destroyed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
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

	std::cout << YELLOW << _name << ": hello, my grade is "<< _grade << RESET << std::endl;
 }


// Getters

int Bureaucrat::getGrade() const {
	return (_grade);
}

std::string Bureaucrat::getName() const {
	return (_name);
}

// i++ / i--

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

// exception

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low\n");
}

// syntactic sugar

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}


// IMPORTANT : a bien maitriser pour la suite, faire refaire et rerefaire

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << _name << " just signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " cant sign the Form " << form.getName() << " because : " << e.what() << std::endl;
	}

}

void Bureaucrat::executeForm(AForm const &form)
{
    try
	{
        form.execute(*this);
        std::cout << GREEN << _name << " executed " << form.getName() << RESET << std::endl;
    }
    catch (const std::exception &e)
	{
        std::cout << RED << _name << " couldn't execute " << form.getName()
                  << " because: " << e.what() << RESET << std::endl;
    }
}

