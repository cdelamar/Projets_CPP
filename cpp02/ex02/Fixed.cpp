#include "Fixed.hpp"
#include <cmath>

// Constructeur par défaut
Fixed::Fixed() : _value(0) {}

// Constructeur avec un entier
Fixed::Fixed(const int value) {
    _value = value << _bits;
}

// Constructeur avec un flottant
Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _bits));
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &other) {
    *this = other; // Utilise l'opérateur d'affectation
}

// Destructeur
Fixed::~Fixed() {}

// Opérateur d'affectation
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

// Getter pour récupérer la valeur brute
int Fixed::getRawBits() const {
    return _value;
}

// Setter pour définir la valeur brute
void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// Conversion en flottant
float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _bits);
}

// Conversion en entier
int Fixed::toInt() const {
    return _value >> _bits;
}

// Surcharges des opérateurs de comparaison
int Fixed::operator<(const Fixed &other) const {
    return _value < other._value;
}

int Fixed::operator>(const Fixed &other) const {
    return _value > other._value;
}

int Fixed::operator<=(const Fixed &other) const {
    return _value <= other._value;
}

int Fixed::operator>=(const Fixed &other) const {
    return _value >= other._value;
}

int Fixed::operator==(const Fixed &other) const {
    return _value == other._value;
}

int Fixed::operator!=(const Fixed &other) const {
    return _value != other._value;
}

// Surcharges des opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other._value == 0) {
        throw std::runtime_error("Division par zéro !");
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Opérateurs d'incrémentation et de décrémentation
Fixed &Fixed::operator++() { // Pré-incrémentation
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) { // Post-incrémentation
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed &Fixed::operator--() { // Pré-décrémentation
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) { // Post-décrémentation
    Fixed temp(*this);
    _value--;
    return temp;
}

// Fonctions statiques min/max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Surcharge de l'opérateur <<
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
