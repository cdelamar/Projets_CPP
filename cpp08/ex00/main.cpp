#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);


    std::cout << "test 1 \n";
    try {
        std::vector<int>::iterator it = easyfind(vec, 34);
        std::cout << "Valeur trouvée : " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }


    std::cout << "\n\ntest 2 \n";
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Valeur trouvée : " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }


    std::cout << "\n\ntest 3 \n";
    try {
        std::vector<int>::iterator it = easyfind(vec, 40);
        std::cout << "Valeur trouvée : " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
