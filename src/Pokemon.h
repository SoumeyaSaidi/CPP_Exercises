#pragma once

#include <string>
#include <memory>

class Trainer;
// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    static int _current_id;

    Pokemon(const std::string& name);
    Pokemon(const Pokemon& pokemon);

    const std::string& name() const { return _name; }
    int id() const { return _id; }

    const Trainer* trainer() const { return _trainer; }

    Pokemon& operator=(const Pokemon& other);

    void set_trainer(const Trainer& trainer) { _trainer = &trainer; }


private:
    std::string _name;
    int _id;
    const Trainer* _trainer = nullptr;
};

using PokemonPtr = std::unique_ptr<Pokemon>;

