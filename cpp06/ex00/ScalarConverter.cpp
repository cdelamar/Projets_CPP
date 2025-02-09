#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {(void)src; return *this; }

static bool isValidType(std::string value, int dataType)
{
	size_t i = 0;
	bool decimal = false;

	if (value[i] == '-' || value[i] == '+')
		i++;

	if (i == value.length())
		return false;

	while(value[i])
	{
		if (value[i] == '.' && dataType == DBL_TYPE)
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
	long result = std::strtol(value.c_str(), &endPtr, 10);

	if (dataType == INT_TYPE && (result > INT_MAX || result < INT_MIN) )
		return false;

	if (dataType == DBL_TYPE && (result > DBL_MAX || result < -DBL_MAX) )
		return false;

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
	errno = 0;
	char *endPtr = NULL;
	double result = std::strtod(value.c_str(), &endPtr);


	if( (errno != 0 &&  *endPtr != '\0') || isValidType(value, DBL_TYPE) == false)
	{
		std::cout << "double: impossible" <<std::endl;
		return ;
	}
	std::cout << "double: " << result <<std::endl;
	return ;
}

void ScalarConverter::convert(std::string value)
{
	charConverter(value);
	intConverter(value);
	doubleConverter(value);
	return ;
}