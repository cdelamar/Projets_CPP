#include "DnD.hpp"

/*
int main ()
{
	Fighter A ("aragorn", 20);
	Fighter B ("araguuurn", 920);

	return 0;
}*/


int main ()
{
	try
	{
		Fighter aragorn("Aragorn", 40);
		Fighter faramir("Faramir", 0);
		//Fighter eomer("Eomer", 0);
	}

	catch (std::exception &e)
	{
		std::cout << "Execption : " << e.what() << std::endl;
	}

	return 0;
}