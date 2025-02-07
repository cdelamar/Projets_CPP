#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructeur par défaut
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), _target("default") {}

// Constructeur avec target
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

// Constructeur de copie
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

// Opérateur d'affectation
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

// Destructeur
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
