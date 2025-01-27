#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

 #include "ClapTrap.hpp"

//viur 'virtual' plus tard quand plusieurs classes heriterons d'une meme classe
class ScavTrap : public ClapTrap {
public :
	ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();

	ScavTrap(std::string name);

	void guardGate();
};

#endif