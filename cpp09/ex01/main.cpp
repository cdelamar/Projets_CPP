#include "RPN.hpp"

int main (int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << " usage : ./RPN <argument>" << std::endl;
		return 1;
	}

	Rpn argument;

	argument.processing(argv[1]);

	return 0;
}