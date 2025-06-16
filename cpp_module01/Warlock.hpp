#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;
class ATarget;

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*> _grimoire;

    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();
        Warlock(const Warlock &other);
        Warlock &operator=(const Warlock &other);

        void introduce() const;
        const std::string &getName() const;
        const std::string &getTitle() const;
        void setTitle(const std::string &title);

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, ATarget &target);

};

#endif