#include "Demon.hpp"

Demon::Demon() : _name("default"), _rank(150) {}
Demon::~Demon() {}
Demon::Demon(const Demon &src) { *this = src; }

Demon &Demon::operator=(const Demon &src) {
	
}
