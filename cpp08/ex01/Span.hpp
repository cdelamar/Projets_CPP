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

};
#endif