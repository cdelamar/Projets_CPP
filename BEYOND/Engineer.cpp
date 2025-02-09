#include "Engineer.hpp"

Engineer::Engineer() : _name("The Engineer"), security_level(20) {}

Engineer::~Engineer() {}

Engineer::Engineer(const Engineer &src)
	: _name(src._name), security_level(src.security_level)
{ *this = src; }

Engineer &Engineer::operator=(const Engineer &src) {
	this->security_level = src.security_level;
	return *this;
}

Engineer::Engineer(const std::string name, int level)
	:_name(name), security_level(level) {}

const char *Engineer::SecurityLevelTooHighException::what() const throw() { return ("Security Level Too High\n"); }
const char *Engineer::SecurityLevelTooLowException::what() const throw() { return ("Security Level Too Low\n"); }

void Engineer::Promote() {
	if (security_level <= 1)
		throw SecurityLevelTooHighException();
	security_level--;
}

void Engineer::Demote() {
	if (security_level >= 150)
		throw SecurityLevelTooLowException();
	security_level++;
}


std::string Engineer::getName() const { return (_name); }
int Engineer::getSecurityLevel() const { return (security_level); }

// operateur et surcharge :
// ici ' << ' est l'operateur de surcharge

/*
Un opérateur peut être :

    unaire (agit sur un seul opérande, comme -a pour inverser un nombre)
    binaire (agit sur deux opérandes, comme a + b)
    ternaire (rare, comme l'opérateur ? :)
*/


std::ostream &operator<<(std::ostream &os, const Engineer &engineer) {
	os << engineer.getName() << ", enginner with Security level " << engineer.getSecurityLevel() << ".";
	return (os);
}
