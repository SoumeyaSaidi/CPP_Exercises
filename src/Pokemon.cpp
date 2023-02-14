#include "Pokemon.h"
#include <string>

using namespace std;

int Pokemon::_current_id = 0;

Pokemon::Pokemon(const string& name)
: _name{name}, _id{_current_id++}
{}

Pokemon::Pokemon(const Pokemon& pokemon)
:_name{pokemon._name}, _id{_current_id++}
{}

Pokemon& Pokemon::operator=(const Pokemon& other)
{
    if (this != &other)
    {
        _name = other._name;
    }

    return *this;
}