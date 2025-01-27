#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog ( Dog &other);
	Dog &operator=(Dog &other);

	std::string getType() const;
	void makeSound() const;
};

#endif