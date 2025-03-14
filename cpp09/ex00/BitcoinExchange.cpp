#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() : _dataBase() {}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &source) : _dataBase(source._dataBase) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
    if (this != &source)
    {
        _dataBase = source._dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDataCsv (const std::string &fileName)
{
    std::ifstream infile(fileName.c_str());
    if (!infile)
    {
        std::cerr << "Error: cant open file " << fileName << std::endl;
        return;
    }

    std::string line;
    std::getline(infile, line); // gnl c++

    while (std::getline(infile, line))
    {
        std::stringstream ss(line); //ss car lecture/ecriture
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
        {
            std::cerr << "Warning: incorrect data line format => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cerr << "Warning: incorrect date => " << date << std::endl;
            continue;
        }

        std::stringstream valueStream(valueStr);
        float value;
        if (!(valueStream >> value)) // si la chaine dans stringstream n'est pas convertible en float
        {
            std::cerr << "Warning: invalid rate here => " << valueStr << std::endl;
            continue;
        }

        _dataBase[date] = value;
    }
    infile.close();
}

float BitcoinExchange::getRate (const std::string &date) const {

}

//methode de parsing > loadDataCsv
bool BitcoinExchange::isValidDate (const std::string &date) const
{
    //substr(0,4) > annee *
    //substr(5,2 > mois **
    //substr(8,2) > jour ***
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') // YYYY-MM-DD
        return false;

    // annee
    std::istringstream iss(date.substr()); //lecture uniquement
    int year; //*
    if(!(iss >> year))
    {
        //potentiel msg erreur
        return false;
    }

    // mois
    iss.clear();
    iss.str(date.substr(5, 2)); // YYYY-xx-DD
    int month; //**
    if(!(iss >> month) || month < 1 || month > 12)
    {
        //potentiel msg erreur
        return false;
    }

    // jour
    iss.clear();
    iss.str(date.substr(8, 2)); // YYYY-MM-xx
    int day;
    if (!(iss >> day) || day < 1 || day > 31)
    {
        //potentiel msg erreur
        return false;
    }




}