#include "Tinker.hpp"

void Tinker::announce() {
	std::cout << "Tinker : Here comes the Tinker, ready to build !" << std::endl;
}

void Tinker::building_sentry() {
	std::cout << "Tinker : Sentry goin' up !" << std::endl;
	building_sentry();
	sentry.announce();
}