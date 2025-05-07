#include "whatever.hpp"

int main( void ) {

    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    //pourquoi min et max sont const ?
    // on touche pas aux valeur, on les test juste pour savoir laquelle est < ou >

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    // pourquoi "::" devant swap ?
    // pour etre sur d'appeler mon template et pas une fonction de la lib std

    //pk swap pas const
    //parce qu'il modifie les valeurs des variable

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}