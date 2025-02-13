#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class Brain;

class Dog : public Animal {
private:
	Brain* brain;

public:
	Dog();
	~Dog();
	Dog (const Dog &other);
	Dog &operator=(const Dog &other);

	std::string getType() const;
	void makeSound() const;
};

#endif