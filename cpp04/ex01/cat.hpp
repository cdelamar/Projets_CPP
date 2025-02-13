#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"

class Brain;

class Cat : public Animal {
private:
	Brain* brain;

public:
	Cat();
	~Cat();
	Cat (const Cat &other);
	Cat &operator=(const Cat &other);

	std::string getType() const;
	void makeSound() const;
};

#endif