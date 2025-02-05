#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat a("Jean Lassalle", 1);
        Bureaucrat b("Jose Bove", 150);
        Bureaucrat c("Philippe", 75);

        Form f1("Formulaire chiant", 50, 25);
        Form f2("Formulaire sans interet", 1, 1);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        std::cout << BLUE <<"---- Tentatives de signature ----" << std::endl << RESET;
        a.signForm(f1);  // ✅
        b.signForm(f1);  // ❌
        c.signForm(f1);  // ✅
        a.signForm(f2);  // ✅
        c.signForm(f2);  // ❌

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
