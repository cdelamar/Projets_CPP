#ifndef ENGINEER_HPP
#define ENGINEER_HPP

#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <string>

class Engineer {
private :
	const std::string _name;
	int security_level;

public :
	Engineer();
	~Engineer();
	Engineer(const Engineer &src);
	Engineer &operator=(const Engineer &src);

	Engineer(const std::string name, int level);

	class SecurityLevelTooLowException : public std::exception
	{ const char *what() const throw(); };
	class SecurityLevelTooHighException : public std::exception
	{ const char *what() const throw(); };

	std::string getName() const;
	int getSecurityLevel() const;

	void Promote();
	void Demote();

};
	std::ostream &operator<<(std::ostream &os, const Engineer &engineer);

#endif