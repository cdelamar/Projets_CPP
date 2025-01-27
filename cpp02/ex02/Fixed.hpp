#ifndef FIXED_HPP
#define FIXED_HPP
//pragmaonce cest bien aussi apparement

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
	int					_value;
	static const int	_bits = 8;

public:
// coplien
// 1. constructeur
// 2. constructeur de recopie
// 3. operateur d'affectation
// 4. destructeur
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

// constructeur ++
// entier et flottant
	Fixed(int n);
	Fixed(float n);

//getter
	int		getRawBits() const;
	void	setRawBits(int const raw);

//setter
	float	toFloat() const;
	int		toInt() const;

// surcharge operators COMPARATIFS (booleens en gros)
int operator<(const Fixed &other) const;
int operator>(const Fixed &other) const;
int operator<=(const Fixed &other) const;
int operator>=(const Fixed &other) const;
int operator==(const Fixed &other) const;
int operator!=(const Fixed &other) const;

// surcharge operator MATHEMATIQUE
Fixed operator+(const Fixed &other) const;
Fixed operator-(const Fixed &other) const;
Fixed operator*(const Fixed &other) const;
Fixed operator/(const Fixed &other) const;

// surcharge operator i++ / i--
Fixed &operator++();	// ++i
Fixed operator++(int);	// i++
Fixed &operator--();	// --i
Fixed operator--(int);	// i--

// min/max
static Fixed &min(Fixed &a, Fixed &b);
static const Fixed &min(const Fixed &a, const Fixed &b);
static Fixed &max(Fixed &a, Fixed &b);
static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

# endif