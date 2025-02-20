#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Constructeur par défaut
    Array() : _data(NULL), _size(0) {}

    // Constructeur avec taille
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Constructeur par copie (deep copy)
    Array(const Array& other) : _data(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }

    // Opérateur d'affectation (deep copy)
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _data = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
        return *this;
    }

    // Opérateur [] avec gestion d'erreur
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    // Getter pour la taille
    unsigned int size() const { return _size; }

    // Destructeur
    ~Array() { delete[] _data; }
};

#endif
