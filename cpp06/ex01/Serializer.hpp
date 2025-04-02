#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <limits>
#include <climits>
#include <cfloat>
#include <stdint.h>

struct Data {
	uintptr_t value;
	std::string dataAdress;

	Data() : value(0), dataAdress("") {}
};

class Serializer {
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif