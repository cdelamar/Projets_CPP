#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::set_contact() {
    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);
}

void Contact::display_summary(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (first_name.size() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|"
              << std::setw(10) << (last_name.size() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|"
              << std::setw(10) << (nickname.size() > 10 ? nickname.substr(0, 9) + "." : nickname) << "\n";
}

void Contact::display_details() const {
    std::cout << "First Name: " << first_name << "\n"
              << "Last Name: " << last_name << "\n"
              << "Nickname: " << nickname << "\n"
              << "Phone Number: " << phone_number << "\n"
              << "Darkest Secret: " << darkest_secret << "\n";
}
