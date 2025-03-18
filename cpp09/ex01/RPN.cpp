#include "RPN.hpp"

Rpn::Rpn() : _stack() {}

Rpn::~Rpn() {}

Rpn::Rpn(const Rpn &source) : _stack(source._stack) {}

Rpn &Rpn::operator=(const Rpn &source) {
	if (this != &source)
		_stack = source._stack;
	return *this;
}

void Rpn::mathOperation(char c) {
	if (_stack.size() < 2)
		throw std::runtime_error(" Not enough values for proper processing");

	// a OP b
	// exemple :
	// ./RPN "89+"
	// a = 8 et b = 9
	// ca se fait en marche arriere
	int b = _stack.front(); // je prend le last de la chaine (le plus recent)
	_stack.pop_front();		// puis je l'enleve de la stack

	int a = _stack.front(); //rebelotte, mais avec le nouveau dernier
	_stack.pop_front() ;	//je le retire aussi

	int result = 0;

	if (c == '+')
		result = a + b;
	else if (c == '-')
		result = a - b;
	else if (c == '*')
		result = a * b;
	else if (c == '/')
	{
		if (b == 0)
			throw std::runtime_error("Division by zero"); //cheh
		result = a / b;
	}
	else
	{
		throw std::runtime_error("Unknown operator '" + std::string(1, c) + "'");
	}

	_stack.push_front(result);

	std::cout << "Operation: " << a << " " << c << " " << b << " = " << result << std::endl;

}

int Rpn::processing(const std::string &arg)
{
	//const_iterator par seucrite, pour lire sans risquer de reecrire dessus
	std::string::const_iterator value = arg.begin();

	while (value != arg.end())
	{
		char token = *value;

		if (token == ' ')
		{
			++value;
			continue;
		}

		if (std::isdigit(token))
		{
			int num = token - '0'; // conversion en entier
			_stack.push_front(num);
			std::cout << "Pushed " << num << std::endl;
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			try
			{
				mathOperation(token);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
				return 1;
			}
		}
		else
		{
			std::cerr << "Invalid character > " << token << std::endl;
			return 1;
		}

		++value;
	}

	// dans le doute bien checker si le resultat est ok
	if (_stack.size() != 1)
	{
		std::cerr << "Error: invalid expression (stack size = " << _stack.size() << ")" << std::endl;
		return 1;
	}

	std::cout << "Final result: " << _stack.front() << std::endl;
	return 0;
}
