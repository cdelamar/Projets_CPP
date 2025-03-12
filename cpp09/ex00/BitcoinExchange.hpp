#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _rates;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    float getRateForDate(const std::string& date) const;
};

bool isValidDate(const std::string& date);
bool isValidValue(const std::string& strValue, float& value);

#endif