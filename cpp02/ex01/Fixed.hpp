#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

//  format Coplien
// 1. constructeur par defaut
// 2. constructeur de copie
// 3. operateur d'affectation
// 4. destructeur


class Fixed {
private:
		int                 _value;                // Stocke la valeur en virgule fixe
		static const int    _bits = 8;             // 8 bits pour la partie fractionnaire

public:
// forme canonique
		Fixed();                                   // Constructeur par défaut
		Fixed(const Fixed &other);                 // Constructeur de recopie
		Fixed &operator=(const Fixed &other);      // Operateur d'affectation
		~Fixed();							                     // Destructeur

// constructeur entier / flottant
		Fixed(int n);
		Fixed(float n);

// setter / getter
		int   getRawBits(void) const;
		void  setRawBits(int const raw);

		float toFloat(void) const;
		int		toInt(void) const;
};

// Surcharge de l'opérateur d'insertion pour std::cout
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif
