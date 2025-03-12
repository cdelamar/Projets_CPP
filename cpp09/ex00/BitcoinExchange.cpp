#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() : _rates() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}


void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    getline(file, line); // Skip the header line

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;

        if (!getline(iss, date, ',') || !getline(iss, valueStr)) {
            std::cerr << "Error: bad line in database => " << line << std::endl;
            continue;
        }

        float value;
        std::istringstream converter(valueStr);
        converter >> value;

        if (converter.fail()) {
            std::cerr << "Error: bad value in database => " << valueStr << std::endl;
            continue;
        }

        _rates[date] = value;
    }

    file.close();
}

float BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);

    if (it != _rates.end() && it->first == date)
        return it->second;

    if (it == _rates.begin())
        throw std::runtime_error("Error: no earlier date found.");

    --it;
    return it->second;
}



bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;

    std::istringstream yearStream(date.substr(0, 4));
    yearStream >> year;
    if (yearStream.fail())
        return false;

    std::istringstream monthStream(date.substr(5, 2));
    monthStream >> month;
    if (monthStream.fail())
        return false;

    std::istringstream dayStream(date.substr(8, 2));
    dayStream >> day;
    if (dayStream.fail())
        return false;

    // Validation basique
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool isValidValue(const std::string& strValue, float& value) {
    std::istringstream iss(strValue);
    iss >> value;

    if (iss.fail() || !iss.eof())
        return false;

    return true;
}
