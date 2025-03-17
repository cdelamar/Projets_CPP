#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>  // std::ifstream
#include <sstream>  // std::stringstream
#include <string>
#include <cstdlib>
#include <iostream>
#include <climits>

class BitcoinExchange {
private:
/**
* @brief container de base de donnee pour l'ex00
*
* malgre sa syntaxe , std::map
* s'avere des plus efficace pour l'ex00, et surement le
* choix le plus evident pour resoudre le probleme,
* grace a sa """"simplicite"""" et son parametrage rapide
* (on a nos date, nos valeurs et voila)
*
* OK MAIS POURQUOI
*
* notre map ici a deux parametre :
* une cle : std::string, les dates
* une valeur , en float
* std::map trie les cle par ordre alphanumerique de base
* parfait pour les dates en questions dans l'ex00
*/
	std::map<std::string, float> _dataBase;
    // std::string _msg;

    bool isValidDate(const std::string &date) const;
    bool isLeapYear(int year) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadCsv(const std::string& filename);
    void processInput(const std::string& filename);
};

#endif
