#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// disclaimer :
// Zero theorie dans ce header,
// pour plus de theorycraft et d'explication
// sur les templates, voir ex01

template<typename T>
T min(T &a, T &b)
{
	return (a < b ? a : b );
}

template<typename T>
T max (T &a, T &b)
{
	return (a > b ? a : b );
}

template<typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

/*

// classe concue pour l'exemple, rien a voir directement avec
// le sujet mais ca rend la correction plus sympa (enfin jtrouve)

class Adventurer {
private:
	std::string _name;
	int			_level;
	int			_hp;

public:

	Adventurer(std::string n, int lvl, int hp) : _name(n), _level(lvl), _hp(hp) {}

	bool operator<(const Adventurer &other) {
		return (this->_level < other._level);
	}
	bool operator>(const Adventurer &other) {
		return (this->_level > other._level);
	}

    std::string getName() const { return _name; }
    int getLevel() const { return _level; }
    int getHP() const { return _hp; }

};


std::ostream& operator<<(std::ostream &os, const Adventurer &a)
{
	os << a.getName() << ", Level " << a.getLevel() << ", " << a.getHP() << " Health Points\n";
	return os;
}

*/

#endif