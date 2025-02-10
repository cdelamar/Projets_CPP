#include "Contact.hpp"
#include <iostream>
#include <iomanip>


void Contact::validInput(const std::string &prompt, std::string &field) {
        std::cout << prompt;
        while (std::getline(std::cin, field)) {
            if (!field.empty())
                break; // Sortie de boucle si l'input est valide
            std::cout << "Erreur : ce champ ne peut pas être vide. Veuillez réessayer.\n" << prompt;
        }
}

void Contact::set_contact() {
    validInput("Enter first name: ", first_name);
    validInput("Enter last name: ", last_name);
    validInput("Enter nickname: ", nickname);
    validInput("Enter phone number: ", phone_number);
    validInput("Enter darkest secret: ", darkest_secret);
}

void Contact::display_summary(int index) const {
    std::cout << std::setfill (' ') << std::setw(10) << index << "|";
    std::cout << std::setfill (' ') << std::setw(10) << (first_name.size() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|";
    std::cout << std::setfill (' ') << std::setw(10) << (last_name.size() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|";
    std::cout << std::setfill (' ') << std::setw(10) << (nickname.size() > 10 ? nickname.substr(0, 9) + "." : nickname) << "\n";
}

void Contact::display_details() const {
    std::cout << "First Name: " << first_name << "\n"
              << "Last Name: " << last_name << "\n"
              << "Nickname: " << nickname << "\n"
              << "Phone Number: " << phone_number << "\n"
              << "Darkest Secret: " << darkest_secret << "\n";
}
