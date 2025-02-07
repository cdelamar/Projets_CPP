#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);

    //code pour lire le fichier (chiant)
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
        throw std::runtime_error("Error opening file");

    file << "     ccee88oo\n"
         << "  C8O8O8Q8PoOb o8oo\n"
         << " dOB69QO8PdUOpugoO9bD\n"
         << "CgggbU8OU qOp qOdoUOdcb\n"
         << "   6OuU  /p u gcoUodpP\n"
         << "      \\//  /douUP\n"
         << "        \\////\n"
         << "         |||\n"
         << "         |||\n"
         << "         |||\n";

    file.close();
    std::cout << "Shrubbery created in " << _target << "_shrubbery" << std::endl;
}
