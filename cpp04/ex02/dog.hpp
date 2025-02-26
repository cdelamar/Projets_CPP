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

    void setBrainIdea(int index, std::string idea);
    std::string getBrainIdea(int index) const;
};

#endif