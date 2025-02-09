#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please enter an argument (./scalar_converter 'value') \n";
		return 0;
	}

	std::string value = argv[1];

	if (value.empty())
	{
		std::cout << "please enter a viable value \n";
		return 0;
	}
	ScalarConverter::convert(value);
	return 0;
}