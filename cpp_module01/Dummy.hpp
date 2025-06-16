#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class Dummy : public ATarget
{
    private:
        std::string _type;
        //Dummy(const Dummy &other);
        //Dummy &operator=(const Dummy &other);

    public:
        Dummy();
        virtual ~Dummy();

        virtual ATarget *clone() const;

};

#endif