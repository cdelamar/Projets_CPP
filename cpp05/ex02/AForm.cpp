#include "AForm.hpp"

	// COPLIEN

AForm::AForm()
	: _name("formulaire chiant"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << RED << "created unsigned " << _name << " form\n" << RESET;
}

AForm::~AForm()
{
	std::cout << RED << "form " << _name << " destroyed\n" << RESET;
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned),
		_gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	std::cout << RED << "copy created of " << _name << " form\n" << RESET ;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return(*this);
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec)
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();

	std::cout << RED << "created unsigned " << _name << " form\n" << RESET;
}

//getters

const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSign() const
{
	return (this->_isSigned);
}

int AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

//fonctions

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	//on regarge si le mec est assez haut lvl pour signer le papier
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();

	this->_isSigned = true;
}

//Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Exception : Grade to High, can't be superior to 1\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Exception : Grade too Low, can't be lower to 150\n");
}

const char *AForm::FormUnsignedExeception::what() const throw()
{
	return ("Form shall be signed up before execution\n");
}

//Syntactic
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm: " << form.getName()
       << ", Signed: " << (form.getSign() ? "Yes" : "No")
       << ", Grade required to sign: " << form.getGradeSign()
       << ", Grade required to execute: " << form.getGradeExec();
    return os;
}


// ex02 nouveaute

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw FormUnsignedExeception();
	if (executor.getGrade() > this->_gradeExec)
		throw GradeTooLowException();
}