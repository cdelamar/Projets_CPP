#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    // constructeur prenant le type de l'arme
    Weapon(std::string type);
    std::string getType();
    void setType(std::string type);
};

#endif
