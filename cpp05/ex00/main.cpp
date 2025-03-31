#include "Bureaucrat.hpp"

int main() {
    try
    {
        Bureaucrat a("Jean Lassalle", 1);
        Bureaucrat b("Jose Bove", 150);
        Bureaucrat c("Philippe", 75);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        std::cout << "Increment Jean Lassalle le goat" << std::endl;
        a.upGrade();  // Va lancer une exception
        std::cout << "decrement jose bove" << std::endl; // ca s'affichera pas c'est normal
        b.downGrade(); // pareil MAIS ne sera jamais atteinte du a l'exception au dessus deja catch
    }

    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // std::cout << "le programme ne s'arrete pas brutalement apres un catch" << std::endl;

    return 0;
}


// double try/catch methode

// int main() {
//     try {
//         Bureaucrat a("Jean Lassalle", 1);
//         std::cout << a << std::endl;
//         std::cout << "Increment Jean Lassalle le goat" << std::endl;
//         a.upGrade();  // Va lancer une exception
//     }
//     catch (std::exception &e) {
//         std::cout << "Exception sur Jean Lassalle: " << e.what();
//     }

//     try {
//         Bureaucrat b("Jose Bove", 150);
//         std::cout << b << std::endl;
//         std::cout << "Decrement Jose Bove" << std::endl;
//         b.downGrade();  // Va aussi lancer une exception
//     }
//     catch (std::exception &e) {
//         std::cout << "Exception sur Jose Bove: " << e.what();
//     }

//     return 0;
// }