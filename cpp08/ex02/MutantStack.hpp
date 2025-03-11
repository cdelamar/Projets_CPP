#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // Canonique Coplien
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    // Type d'itérateur minimal
    typedef typename std::stack<T>::container_type::iterator iterator;

    // Méthodes minimalistes
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif