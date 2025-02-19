#include "whatever.hpp"
/*
int main() {
    std::cout << "==== 🏰 DnD ====\n";

    // 🛡️ Test sur les points de vie
    int hp1 = 30, hp2 = 45;
    std::cout << "HP1: " << hp1 << ", HP2:" << hp2 << std::endl;
    std::cout << "Min HP: " << min(hp1, hp2) << std::endl;
    std::cout << "Max HP: " << max(hp1, hp2) << std::endl;
    swap(hp1, hp2);
    std::cout << "After swap -> HP1: " << hp1 << ", HP2: " << hp2 << "\n\n";

    std::string name1 = "Gimli ⚒", name2 = "Legolas 🏹";
    std::cout << "Adventurers: " << name1 << " vs " << name2 << std::endl;
    std::cout << "Min Name: " << min(name1, name2) << std::endl;
    std::cout << "Max Name: " << max(name1, name2) << std::endl;
    swap(name1, name2);
    std::cout << "After swap -> Name1: " << name1 << ", Name2: " << name2 << "\n\n";

    Adventurer hero1("Aragorn ⚔", 100, 5);
    Adventurer hero2("Gandalf ✨", 120, 10);

    std::cout << "Adventurers:\nheor1:" << hero1 << " vs \nhero2:" << hero2 << std::endl;
    std::cout << "Min Level: " << min(hero1, hero2) << std::endl;
    std::cout << "Max Level: " << max(hero1, hero2) << std::endl;
    swap(hero1, hero2);
    std::cout << "After swap ->\nHero1: " << hero1 << ", Hero2: " << hero2 << "\n\n";

    return 0;
}*/


int main( void ) {

    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}