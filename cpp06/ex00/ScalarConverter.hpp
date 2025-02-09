#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <limits>
#include <climits>
#include <cfloat>

#define INT_TYPE	0
#define DBL_TYPE	1
#define FLO_TYPE	2

class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);

public:
	static void convert(std::string value);
};

#endif