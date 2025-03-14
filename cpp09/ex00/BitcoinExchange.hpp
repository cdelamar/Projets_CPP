#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>  // std::ifstream
#include <sstream>  // std::stringstream
#include <string>
#include <cstdlib>


class BitcoinExchange {
private:
/**
* @brief container de base de donnee pour l'ex00
*
* malgre sa syntaxe completement degueulasse, std::map
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
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &source);
    BitcoinExchange &operator=(const BitcoinExchange &source);

    void loadDataCsv (const std::string &fileName);
	float getRate (const std::string &date) const; // const pour pas modifier et & pour eviter une copie

    // sous methodes a utiliser dans loadDataCsv
    bool isValidDate (const std::string &date) const;

};

#endif
