#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _stackVector(), _stackDeque() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) : _stackVector(src._stackVector), _stackDeque(src._stackDeque)  {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->_stackVector = rhs._stackVector;
        this->_stackDeque = rhs._stackDeque;
    }
    return *this;
}

void PmergeMe::printBefore(char **argv)
{
	std::cout << "Before: ";

	for (int i = 1; argv[i] != NULL; ++i)
		std::cout << argv[i] << " ";

	std::cout << std::endl;
}

void PmergeMe::printAfter()
{
	std::vector<int>::const_iterator i = _stackVector.begin();
	std::cout << "After: ";

	while (i != _stackVector.end())
	{
		std::cout << *i << " ";
		++i;
	}

	std::cout << std::endl;
}

/*
un schema tres simple :

Liste de départ : [7, 3, 5, 9, 2]

Etape 1 : Paires ➔ (7,3), (5,9), (2)
Etape 2 : Trier les paires ➔ [(3,7), (5,9)]
Etape 3 : mainChain = [7,9,2], pend = [3,5]

Etape 4 : Trier mainChain ➔ [2,7,9]

Etape 5 : Insérer pend ➔
    ➔ Insert 3 ➔ [2,3,7,9]
    ➔ Insert 5 ➔ [2,3,5,7,9]
*/

void PmergeMe::sortVector()
{
	if (_stackVector.size() <= 1)
		return; // si ya qu'un chiffre

	std::vector<int> mainChain;
	std::vector<int> pend;

	// on cree des paires
	for (int i = 0; i < _stackVector.size(); i += 2)
	{
		if (i + 1 < _stackVector.size()) // si jai assez pour une pair
		{
			int first = _stackVector[i];
			int second = _stackVector[i + 1];

			if (first > second)
				std::swap(first, second);

			mainChain.push_back(second); // Le plus grand va dans mainChain
			pend.push_back(first);       // Le plus petit est en attente dans pend

		}

		else
		{
			// si il reste une valeur tout seul, direct dans mainchain
			mainChain.push_back(_stackVector[i]);
		}
	}

	// Tri des paires de la mainchain
	for (int i = 1; i < mainChain.size(); ++i)
	{
		int key = mainChain[i];
		int j = i;
		/*
		un exemple concret pour la boucle ci dessous :

		main Chain = [2, 4, 7, 5, 9]

		si j'arrive a i = 3 :
		key = 5 et j = 3 (j = i)
		[2, 4, 7, 5, 9]
				  ^key (mainChain[3])

		j - 1 est donc plus grand que key (7 > 5)
		in donne 7 a mainchain[j]

		on decremente
		et on rejoute key
		*/
		while (j > 0 && mainChain[j - 1] > key)
		{
			mainChain[j] = mainChain[j - 1];
			--j;
		}
		mainChain[j] = key;

		// EN BREF :
		// cette boucle marche a peu pres comme un std::swap
		// a l'exception pres que l'on DECALE la valeur plutot que 
		// de l'echanger
	}

	// insertion des petites valeurs (pend) dans la mainchain
	for (int i = 0; i < pend.size(); ++i)
	{
		int toInsert = pend[i];

		// Recherche de la bonne position dans la mainChain (equivalent a une insertion binaire)
		// ici, c'est lower_bound qui fait le boulot :
		// il s'occupe de pend[i] en cherchant dans le container sa place-
		// SI on trouve une valeur plus grande (ou egal mais ca n'arrivera pas dans cet exo)
		// alors on utilise insert sur la position (pos) qu'on a sauvegarder
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), toInsert);
		mainChain.insert(pos, toInsert);
		//differences pertinentes entre un iterator et un pointeur dans une chaine de char
		// iterator n'est pas natif au langage (std::, il est gere la par la STL), contrairement aux pointeurs
		// une analogie dangereuse, car il arrive d'appeler le pointeur vers ce container (*it par ex), donc pas tout a fait pareil
		// un pointeur n'a aucune securite, iterator est moins dangereux
		// iterator ne se cantonne qu'a son container DANS LES LIMITES DE LA LOGIQUE DU PROGRAMME,
		// alors qu'un pointeur reste un pointeur
	}

	// mise a jour et voila
	_stackVector = mainChain;
}

void PmergeMe::sortDeque ()
{
	if (_stackDeque.size() <= 1)
		return;

	std::deque<int> mainChain;
	std::deque<int> pend;

	for(int i = 0; i <= _stackDeque.size(); i += 2)
	{
		if (i + 1 <_stackDeque.size())
		{
			int first = _stackDeque[i];
			int second = _stackDeque[i + 1];

			if (first > second)
				std::swap(first, second);

			mainChain.push_back(second);
			mainChain.push_back(first);
		}

		else
		{
			mainChain.push_back(_stackDeque[i]);
		}
	}

	for(int i = 0; i < mainChain.size(); ++i)
	{
		int key = mainChain[i];
		int j = i;

		while (j > 0 && mainChain[j - 1] > key)
		{
			mainChain[j] = mainChain[j - 1];
			--j;
		}
		mainChain[j] = key;
	}

	for (int i = 0; i < pend.size(); ++i)
	{
		int toInsert = pend[i];

		std:deque<int>::iterator pos = std::lower
	}
}


void PmergeMe::exec (char **argv)
{
	try
	{
		parseArgs(argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}

	printBefore(argv);

	clock_t start;
	clock_t end;

	// Vector
	start = clock();
	sortVector();
	end = clock();
	double vectorChrono = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; //microSec

	// Deque
	start = clock();
	sortDeque();
	end = clock();
	double dequeChrono = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; //microSec

	printAfter();

	std::cout << "vector Timer : " << vectorChrono << " microsec" << std::endl;
	std::cout << "deque Timer : " << dequeChrono << " microsec" << std::endl;
}