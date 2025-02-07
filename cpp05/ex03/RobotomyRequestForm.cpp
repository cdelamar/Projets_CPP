#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);

    std::cout << "* Drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "The robotomy on " << _target << " failed!" << std::endl;
}
