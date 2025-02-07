#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // Pour rand()

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    // Canonical Form Coplien (C++98)
    RobotomyRequestForm();
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    // Constructeur principal
    RobotomyRequestForm(std::string target);

    void execute(Bureaucrat const &executor) const;
};

#endif
