#ifndef HEAD_HPP
#define HEAD_HPP

#include <string>
#include <iostream>

class Animal {
private :
	void speak();
	void eat();
	void sleep();

public :
	void actions (std::string act);
};

#endif