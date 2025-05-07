#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 2;

        std::cout << "Tableau d'entiers : ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        Array<int> b = a;
        b[0] = 42;  // Verif deep copie

        std::cout << "Copie modifiee : ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        // Test avec des strings
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "World";
        strArr[2] = "!";

        std::cout << "Tableau de strings : ";
        for (unsigned int i = 0; i < strArr.size(); i++)
            std::cout << strArr[i] << " ";
        std::cout << std::endl;

        // Test exception
        std::cout << strArr[5] << std::endl;  // Doit lever une exception a ce moment la

    }

    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}
