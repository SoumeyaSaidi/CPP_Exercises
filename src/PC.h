#pragma once

#include "Pokemon.h"
#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    void transfer(PokemonPtr pointer) {
        _pokemons.emplace_back(std::move(pointer));
    }

    const std::vector<PokemonPtr>& pokemons() const { return _pokemons; }
private: 
    std::vector<PokemonPtr> _pokemons;
};
