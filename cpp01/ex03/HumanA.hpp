#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
private:
    std::string name;
    Weapon& weapon;        // HumanA est TOUJOURS arme, donc reference

public:
    HumanA(std::string name, Weapon& weapon);
    void attack();
};

#endif
