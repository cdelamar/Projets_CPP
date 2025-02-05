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

    }

    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


/*int main()
{
	Bureaucrat b1;
	Bureaucrat b2("gerald", 140);
	b2.upGrade();
	b1.downGrade();

	Bureaucrat b3 = b2;
	Bureaucrat b4 = b1;


	return 0;
}*/