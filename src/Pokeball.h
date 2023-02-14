#pragma once

#include <vector>
#include <utility>
#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const { return _pokemon == nullptr; }

    void store(PokemonPtr pointer) {
        _pokemon = std::move(pointer);
    }

    const Pokemon& pokemon() const { return *_pokemon; }

    PokemonPtr steal() { return std::move(_pokemon); }

private:
    PokemonPtr _pokemon;
};

