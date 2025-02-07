#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class AForm;

class ShrubberyCreationForm : public AForm
{
private :
	std::string _target;

// coplien
public:
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	ShrubberyCreationForm(std::string target);
	void execute(Bureaucrat const &executor) const;
};

#endif