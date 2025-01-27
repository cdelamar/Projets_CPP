#include <iostream> // Inclure la bibliothèque pour les entrées/sorties
#include <cctype>   // Inclure la bibliothèque pour les fonctions de manipulation de caractères (comme toupper)

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        int j = 0;
        while (argv[i][j])
        {
            std::cout << (char)toupper(argv[i][j]);
            j++;
        }
    }
    std::cout << std::endl; // printf '\n'
    return 0;
}