#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *tab, size_t len, void (*foo)(T &src))
{
	for (size_t i = 0; i < len; i++)
		foo(tab[i]);
}

#endif