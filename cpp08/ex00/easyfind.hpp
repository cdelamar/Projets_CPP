#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <vector>
#include <algorithm>

// le type T pris par easyfind est par principe un
// container d'entier


template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("Valeur non trouvée");

    return it;  // Retourne un iterateur sur elemet trouve
}


#endif