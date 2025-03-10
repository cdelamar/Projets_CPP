#include "Span.hpp"

Span::Span() : _capacity(0), _values() {}

Span::Span(unsigned int N) : _capacity(N), _values() {
	_values.reserve(N); // experimental, on perd un peut l'interet des vector
						// mais on limite la size pour l'exercice en cas de test relou
						// a la correction
}

Span::~Span() {}

Span::Span(const Span &other) : _capacity(other._capacity), _values(other._values) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _values = other._values;
    }
    return *this;
}

void Span::addNumber(int n)
{
	if (_values.size() >= _capacity)
		throw std::runtime_error("Span is full");

	_values.push_back(n);
}

int Span::shortestSpan()
{
	if (_values.size() < 2)
		throw std::runtime_error("We need at least 2 values to find a span");

	std::vector<int> sortedCopy = _values; // copie de contianer a trier
	std::sort(sortedCopy.begin(), sortedCopy.end());

	int minSpan = sortedCopy[1] - sortedCopy[0];

	for (size_t i = 1; i < sortedCopy.size() - 1; ++i)
	{
		int diff = sortedCopy[i + 1] - sortedCopy[i];
		if (diff < minSpan)
			minSpan = diff;
	}

	return minSpan;
}

int Span::longestSpan()
{
	if (_values.size() < 2)
		throw std::runtime_error("We need at least 2 values to find a span");

	int minValue = *std::min_element(_values.begin(), _values.end());
	int maxValue = *std::max_element(_values.begin(), _values.end());

	return maxValue - minValue;
}

/*
int Span::longestSpan()
{
	if (_values.size() < 2)
		throw std::runtime_error("We need at least 2 values to find a span");

	std::vector<int> sortedCopy = _values; // copie de contianer a trier
	std::sort(sortedCopy.begin(), sortedCopy.end());

	int maxSpan = sortedCopy[1] - sortedCopy[0];

	for (int i = 1; i < sortedCopy.size() - 1; ++i)
	{
		int diff = sortedCopy[i + 1] - sortedCopy[i];
		if (diff > maxSpan)
			maxSpan = diff;
	}

	return maxSpan;
}*/