#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
    private:
        std::string _type;

    public:
        ATarget(const std::string &type);
        virtual ~ATarget();
        ATarget(const ATarget &other);
        ATarget &operator=(const ATarget &other);

        const std::string &getType() const;

        virtual ATarget *clone() const = 0;
        void getHitBySpell(const ASpell &spell) const;
};

#endif