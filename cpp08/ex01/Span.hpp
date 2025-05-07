#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
private:
	unsigned int _capacity;
	std::vector<int> _values;

public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);

	void addNumber(int n);
	int	 shortestSpan();
	int	 longestSpan();

	// la plage iterateur : template donc a faire dans le hpp
	template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
	{
        for (Iterator it = begin; it != end; ++it)
            addNumber(*it); // Reutilisation de l'existant
    }

};
#endif