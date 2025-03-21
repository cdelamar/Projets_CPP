#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [positive integers...]" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.exec(argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}