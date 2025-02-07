#ifndef PRESIDENTIALPARDONDORM_HPP
#define PRESIDENTIALPARDONDORM_HPP

#include "AForm.hpp"
class AForm;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
// coplien (C++98 oblige)
	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

//heritage de la class pure virtual par AForm
	PresidentialPardonForm(std::string target);
	void execute(Bureaucrat const &executor) const;
};

#endif