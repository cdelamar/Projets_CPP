#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string type;

public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal (const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType() const;
	void makeSound() const;
};

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat (WrongCat &other);
	WrongCat &operator=(WrongCat &other);

	std::string getType() const;
	void makeSound() const;
};


#endif