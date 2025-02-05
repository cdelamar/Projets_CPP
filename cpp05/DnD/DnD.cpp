#include "DnD.hpp"

	Fighter::Fighter(const std::string name, int rank)
		: _name(name), _rank(rank)
	{
		std::cout << _name << ", level " << _rank << " ,has entered the dungeon\n";
	}
	Fighter::~Fighter()
	{
		std::cout << _name << " has left\n";
	}
	Fighter::Fighter(const Fighter &other)
	{
		std::cout << "COPY : " << _name << ", level " << _rank << " ,has entered the dungeon\n";

	}

	Fighter &Fighter::operator=(const Fighter &other)
	{
		if (this != &other)
			this->_rank = other._rank;
		return(*this);
	}

	
