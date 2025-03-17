#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

// ------------- Coplien Form -------------
BitcoinExchange::BitcoinExchange() : _dataBase() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _dataBase(other._dataBase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _dataBase = other._dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// ------------- Utilities -------------
bool BitcoinExchange::isLeapYear(int year) const
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28),
                         31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

// ------------- CSV Loader -------------
void BitcoinExchange::loadCsv(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float rate;
        std::istringstream vs(valueStr);
        if (!(vs >> rate))
        {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        _dataBase[date] = rate;
    }

    file.close();
}

// ------------- Process Input File -------------
void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        // Date validation
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Value validation
        double value;
        std::istringstream vs(valueStr);
        if (!(vs >> value))
        {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Find rate (lower_bound)
        std::map<std::string, float>::const_iterator it = _dataBase.lower_bound(date);
        if (it == _dataBase.end() || it->first != date)
        {
            if (it == _dataBase.begin())
            {
                std::cerr << "Error: no earlier date for " << date << std::endl;
                continue;
            }
            --it;
        }

        float rate = it->second;
        double result = value * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    file.close();
}
