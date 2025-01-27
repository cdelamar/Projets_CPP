#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


//  format Coplien
// 1. constructeur par defaut
// 2. constructeur de copie
// 3. operateur d'affectation
// 4. destructeur


class Fixed {
private:
    int                 _fixed_point_value;               // Stocke la valeur en virgule fixe
    static const int    _fractional_bits = 8;             // 8 bits pour la partie fractionnaire

public:
    Fixed();                                  // Constructeur par défaut
    Fixed(const Fixed &src);                 // Constructeur de recopie
    Fixed &operator=(const Fixed &rhs);      // Opérateur d'affectation
    ~Fixed();                                // Destructeur

    int getRawBits(void) const;              // Getter
    void setRawBits(int const raw);          // Setter
};

#endif
