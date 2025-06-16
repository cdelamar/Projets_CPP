#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
:_name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!\n";
}

Warlock::Warlock(const Warlock &other)
:_name(other._name), _title(other._title)
{

}

Warlock &Warlock::operator=(const Warlock &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_title = other._title;
    }

    return (*this);
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

const std::string &Warlock::getName() const
{
    return (_name);
}

const std::string &Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(const std::string &title)
{
    _title = title;
}


void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
    {
        std::string spellName = spell->getName();
        if (_grimoire.count(spellName) == 0)
            _grimoire[spellName] = spell->clone();
    }
}

void Warlock::forgetSpell(std::string spellName)
{
    std::map<std::string, ASpell*>::iterator it;
    it = _grimoire.find(spellName);

    if (it != _grimoire.end())
    {
        delete it->second;
        _grimoire.erase(it);
    }
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
    std::map<std::string, ASpell*>::iterator it;

    it = _grimoire.find(spellName);

    if (it != _grimoire.end())
        it->second->launch(target);
}