#include "MutantStack.hpp"
#include <iostream>

int main()
{
MutantStack<int>
mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}
/* tuto */

/*
MutantStack<int> mstack;

mstack.push(10);
mstack.push(20);
mstack.push(30);

std::cout << "Top: " << mstack.top() << std::endl; // Doit afficher 30

mstack.pop();

std::cout << "Top après pop: " << mstack.top() << std::endl; //  20
std::cout << "Size: " << mstack.size() << std::endl;         //  2*/