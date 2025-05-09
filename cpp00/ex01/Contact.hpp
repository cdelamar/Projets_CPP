#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	void set_contact();
	void display_summary(int index) const;
	void display_details() const;
	void validInput(const std::string &prompt, std::string &field);
};

#endif

