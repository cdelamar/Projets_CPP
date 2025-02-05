#include "Form.hpp"

	// COPLIEN

Form::Form()
	: _name("formulaire chiant"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << RED << "created unsigned " << _name << " form\n" << RESET;
}

Form::~Form()
{
	std::cout << RED << "form " << _name << " destroyed\n" << RESET;
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
		_gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	std::cout << RED << "copy created of " << _name << " form\n" << RESET ;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return(*this);
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec)
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();

	std::cout << RED << "created unsigned " << _name << " form\n" << RESET;
}

//getters

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSign() const
{
	return (this->_isSigned);
}

int Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int Form::getGradeExec() const
{
	return (this->_gradeExec);
}

//fonctions
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	//on regarge si le mec est assez haut lvl pour signer le papier
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();

	this->_isSigned = true;
}

//Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Exception : Grade to High, can't be superior to 1\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Exception : Grade too Low, can't be lower to 150\n");
}



//Syntactic
std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getSign() ? "Yes" : "No")
       << ", Grade required to sign: " << form.getGradeSign()
       << ", Grade required to execute: " << form.getGradeExec();
    return os;
}
