#include "Sentry.hpp"

void Sentry::announce() {
	std::cout << "Sentry : --- BEEP..BOOP..BEEP..BOOP ---" << std::endl;
}

void Sentry::shoot() {
	--ammo;
	if (ammo == 0)
	{
		std::cout << "Sentry : *tic - tic* ! No more ammo, please reload." << std::endl;
		return;
	}
	std::cout << "Sentry : Pew ! ammo left : " << ammo << std::endl;
	return;
}