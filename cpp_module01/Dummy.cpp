#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"

Dummy::Dummy()
:ATarget("Target Practice Dummy")
{

}

Dummy::~Dummy()
{

}

ATarget *Dummy::clone() const
{
    return new Dummy(*this);
}
