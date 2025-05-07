#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

/*
on cree une class TEMPLATE

Array<T> :

    c'est un tableau classique mais safe
    il fonctionne avec n'importe quel type

operator[] :

    acces simple aux variable du tableau par index
    letcure par :
                    int x = array[2];
    ecriture par :
                    array[2] = 42;

     *** un peu comme un getter/setter ***

    throw integrer pour gerer les erreurs (try / catch)

*/

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    Array(const Array& other) : _data(new T[other._size]), _size(other._size)
    {
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _data;
            _data = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = other._data[i];
        }
        return *this;
    }

    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    T const &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    unsigned int size() const { return _size; }

    ~Array() { delete[] _data; }
};

#endif
