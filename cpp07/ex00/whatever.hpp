#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
T min(T &a, T &b) { return (a < b ? a : b ); }
// T est une 'PLACEHOLDER'
// ca veut dire que le type de variable utiliser
//est encore inconnu a ce stade de l'ecriute de ma focntion


template<typename T>
T const &min(T const &a, T const &b) { return (a < b ? a : b); }

template<typename T>
T max (T &a, T &b) { return (a > b ? a : b ); }

template<typename T>
T const &max(T const &a, T const &b) { return (a > b ? a : b); }

template<typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

#endif