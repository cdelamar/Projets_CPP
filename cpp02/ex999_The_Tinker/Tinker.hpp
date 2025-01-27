#ifndef TINKER_HPP
#define TINKER_HPP

#include <iostream>
#include <string>
#include "Sentry.hpp"

class Sentry;

class Tinker {
private:
	class Sentry;
	std::string repairing_tool; //variable able to set to NULL
	std::string tool_box; //absolute constant variable
public:
	void announce();
	void building_sentry(); //inner class 'SentryGun'
	//int searching_tools(tool_box, repairing_tool);
	//void repairing_sentry();
};

#endif