#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phonebook.add_contact();
        } else if (command == "SEARCH") {
            phonebook.search_contacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "command invalid\n";
        }
    }
    return 0;
}

