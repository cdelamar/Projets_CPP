#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>
#include <iostream>
#include <cctype>

class Rpn {
private:
	std::list<int> _stack;
	void mathOperation(char c);

public:
	Rpn();
	Rpn(const Rpn &source);
	Rpn &operator=(const Rpn &source);
	~Rpn();

	int processing(const std::string &arg);
};

#endif