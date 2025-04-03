#include "ScalarConverter.hpp"

	ScalarConverter::ScalarConverter() {}
	ScalarConverter::~ScalarConverter() {}
	ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
	ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
    {
        (void)src;
        return *this;
    }

// std::strtol  : convertit une chaîne en long (base donnée), stocke dans un pointeur la fin de la conversion.
// std::strtof  : convertit une chaîne en float.
// std::strtod  : convertit une chaîne en double.
// std::isprint : retourne vrai si le caractère est affichable.
// std::isdigit : retourne vrai si le caractère est un chiffre.
// std::fixed   : formatte le flux pour un affichage à virgule fixe.
// std::setprecision(n) : fixe le nombre de chiffres après la virgule.
// isnan        : retourne vrai si la valeur est NaN (Not a Number).

static bool isChar(const std::string &literal) {
    return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

static bool isInt(const std::string &literal) {
    char *end;
    long val = std::strtol(literal.c_str(), &end, 10);
    return (*end == '\0' && val >= INT_MIN && val <= INT_MAX);
}

static bool isFloat(const std::string &literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    char *end;
    std::strtof(literal.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string &literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    char *end;
    std::strtod(literal.c_str(), &end);
    return (*end == '\0');
}

static void printChar(double value) {
    if (isnan(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value) {
    if (isnan(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    double value;

    if (isChar(literal)) {
        value = static_cast<double>(literal[0]);
    } else if (isInt(literal)) {
        value = static_cast<double>(std::atoi(literal.c_str()));
    } else if (isFloat(literal)) {
        value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    } else if (isDouble(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}