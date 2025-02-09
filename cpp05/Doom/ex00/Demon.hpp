#ifndef DEMON_HPP
#define DEMON_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

class Demon {
private:
	const std::string _name;
	int	_rank;

public:
	Demon();
	~Demon();
	Demon(const Demon &src);
	Demon operator=(const Demon &src);
	Demon(const std::string name, int rank);

	const std::string getName();
	int getRank();

	void promote();
	void demote();

	class RankTooHighException : public std::exception { const char *what() const throw(); };
	class RankTooLowException : public std::exception { const char *what() const throw(); };

};

#endif