#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : total_contacts(0), next_index(0) {}

void PhoneBook::add_contact() {
    if (total_contacts < 8)
        total_contacts++;
    contacts[next_index].set_contact();
    next_index = (next_index + 1) % 8;
}

void PhoneBook::search_contacts() const {
    if (total_contacts == 0) {
        std::cout << "No contacts yet\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";

    for (int i = 0; i < total_contacts; i++) {
        contacts[i].display_summary(i);
    }

    std::cout << "Enter contact index: ";
    std::string input;
    std::getline(std::cin, input);

    // Conversion manuelle de chaîne en entier
    int index = -1;
    bool is_valid = true;
    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            is_valid = false;
            break;
        }
    }

    if (is_valid) {
        index = 0;
        for (size_t i = 0; i < input.length(); i++) {
            index = index * 10 + (input[i] - '0');
        }
    }

    if (!is_valid || index < 0 || index >= total_contacts) {
        std::cout << "invalid index\n";
    } else {
        contacts[index].display_details();
    }
}


