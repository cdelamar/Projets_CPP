#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {(void)src; return *this; }

static bool floatPseudo(std::string value)
{
	return (value == "nanf" || value == "+inff" || value == "-inff");
}
static bool doublePseudo(std::string value)
{
	return  (value == "nan" || value == "+inf" || value == "-inf");
}

static bool isValidType(std::string value, int dataType)
{
	size_t i = 0;
	bool decimal = false;
	errno = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;

	if (i == value.length())
		return false;

	while(value[i])
	{
		if (value[i] == '.' && (dataType == DBL_TYPE || dataType == FLT_TYPE))
		{
			if (decimal || i == 0 )
				return false;
			decimal = true;
		}
		else if (!std::isdigit(value[i]))
			return false;
		i++;
	}

	char *endPtr = NULL;

	if (dataType == INT_TYPE)
	{
		long result = std::strtol(value.c_str(), &endPtr, 10);

		if (errno != 0 && dataType == INT_TYPE && (result > INT_MAX || result < INT_MIN) )
			return false;
	}

	else if (dataType == DBL_TYPE)
	{
		double result = std::strtod(value.c_str(), &endPtr);
		if (errno != 0 && dataType == DBL_TYPE && (result > DBL_MAX || result < -DBL_MAX) )
			return false;
	}

	else if (dataType == FLT_TYPE)
	{
		float result = std::strtof(value.c_str(), &endPtr);
		if (dataType == FLT_TYPE && (result > FLT_MAX || result < -FLT_MAX) )
			return false;
	}

	return true;
}

static bool isChar(std::string value)
{
	return (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0])) ;
}

static void charConverter (std::string value)
{
	if (isChar(value))
		std::cout << "char : " << value << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
	return ;
}

static void intConverter(const std::string value)
{
	if (isValidType(value, INT_TYPE) == false)
	{
		std::cout << "int: impossible" <<std::endl;
		return;
	}

	long long_value = std::strtol(value.c_str(), NULL, 10);
	int result;
	result = static_cast<int>(long_value);
	std::cout << "int: " << result << std::endl;
	return ;
}

static void doubleConverter(const std::string value)
{
	if (doublePseudo(value))
	{
		std::cout << "double: " << value << std::endl;
		return;
	}


	if (value == "nanf")
	{
		std::cout << "double: nan" << std::endl;
		return;
	}

	errno = 0;
	char *endPtr = NULL;
	double result = std::strtod(value.c_str(), &endPtr);


	if( (errno != 0 &&  *endPtr != '\0') || isValidType(value, DBL_TYPE) == false)
	{
		std::cout << "double: impossible" <<std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << result <<std::endl;
	return ;
}

static void floatConverter(const std::string value)
{
	if (floatPseudo(value))
	{
		std::cout << "float: " << value << std::endl;
		return;
	}

	if (value == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		return;
	}

	errno = 0;
	char *endPtr = NULL;
	float result = std::strtof(value.c_str(), &endPtr);

	if (errno != 0 && (*endPtr != '\0' || isValidType(value, FLT_TYPE) == false) )
	{
		std::cout << "float: impossible" <<std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << result << "f" << std::endl;
	return ;
}

void ScalarConverter::convert(std::string value)
{
	charConverter(value);
	intConverter(value);
	doubleConverter(value);
	floatConverter(value);
	return ;
}