#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructeur entier
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _value = n << _bits;  // Décalage binaire = multiplication par 256
}

// Constructeur flottant
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(n * (1 << _bits));  // Conversion correcte en virgule fixe
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = other.getRawBits();  // Copie directe
}

// Opérateur d'affectation
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

// Destructeur
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const {
    return this->_value;
}

// Setter
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// Conversion en int
int Fixed::toInt() const {
    int result = _value >> _bits;
    return result;
}

// Conversion en float
float Fixed::toFloat() const {
    float result = (float)_value / (1 << _bits);
    return result;
}

// Surcharge de l'opérateur <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();  // Affichage de la valeur flo
	return out;
}