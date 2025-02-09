#include "Engineer.hpp"


int main ()
{
	try
	{
		Engineer cdelamar("Clement", 14);
		Engineer vipr("Vipr", 1400);
		std::cout << cdelamar << std::endl;
	}

	catch (std::exception &src)
	{
		std::cout << "EXCEPTION >>> " << src.what() << std::endl;
	}

	return 0;
}