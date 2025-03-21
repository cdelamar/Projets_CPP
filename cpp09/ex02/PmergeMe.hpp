#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class PmergeMe
{
	private:
		// vector
		// . acces rapide par index, comme un char ** en C
		// . memoire "contigue" : en gros c'est stocke a la suite tout simplement
		// . a priori opti pour Ford Johnson
		std::vector<int> _stackVector;
		// deque
		// . acces preferable par insertion head/tail (debut et fin en gros)
		// . acces par index possible mais memoire fragmentee
		// . une alternative interessante a vector, mais pas de stockage contigue
		// . memoire coupee en "chuncks" (bloc de donnees dispersees)
		// . du coup ya des truc plus risque qu'avec vector
		// . il en fallait deux, tfacon
		std::deque<int> _stackDeque;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);

		void parseArgs(char **argv);
		void fillContainer(char **argv);

		void printBefore(char **argv);
		void printAfter();

		void sortVector();
		void sortDeque();

		void exec(char **argv);
};

#endif