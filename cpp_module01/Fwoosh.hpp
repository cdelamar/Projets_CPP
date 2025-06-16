#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
    private:
        std::string _name;
        std::string _effects;
        // Fwoosh &operator=(const Fwoosh &other);
        // Fwoosh(const Fwoosh &other);
        
        public:
        Fwoosh();
        virtual ~Fwoosh();

        virtual ASpell *clone() const;

};

#endif