#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"

class Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat (Cat &other);
	Cat &operator=(Cat &other);

	std::string getType() const;
	void makeSound() const;
};

#endif