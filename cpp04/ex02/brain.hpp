#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
	std::string idea[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	std::string getBrainIdea(int index);
	void setBrainIdea(int index, std::string &idea);
};

#endif