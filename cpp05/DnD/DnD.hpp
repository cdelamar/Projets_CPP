#ifndef DND_HPP
#define DND_HPP

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class Fighter
{
private:
	const std::string _name;
	int 	_rank;

public:
	Fighter(const std::string name, int rank);
	~Fighter();
	Fighter(const Fighter &other);
	Fighter &operator=(const Fighter &other);

	int getRank();
	std::string getName();

	class RankTooHigh : public std::exception {
		const char *what() const throw();
	};

	class RankTooLow : public std::exception {
		const char *what() const throw();
	};

};


#endif