#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int total_contacts;
    int next_index;

public:
    PhoneBook();
    void add_contact();
    void search_contacts() const;
};

#endif
