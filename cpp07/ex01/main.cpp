# include "iter.hpp"
# include <iostream>

void print_coucou(int &n)
{
	std::cout << "coucou " << n << std::endl;
}


void doublette(int &n)
{
		std::cout << n << " devient " << n*2 << std::endl;
}

int main ()
{
	int tab[] = {1, 2, 3, 4};

	iter(tab, 4, print_coucou);
	iter(tab, 4, doublette);

	return 0;
}