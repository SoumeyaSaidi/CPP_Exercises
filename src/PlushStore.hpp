#pragma once

#include <string>
#include <algorithm>
#include <vector>
#include <optional>
#include <iostream>
#include "Plush.hpp"

class PlushStore {
public:
    PlushStore(const std::string& name)
    : _name{name}
    {}

    const std::string& get_name() const { return _name; }
    unsigned int get_wealth_amount() const { return _wealth_amount; }
    unsigned int get_stock_size() const { return _stock_size; }
    unsigned int get_debt_amount() const { return _debt_amount; }
    unsigned int get_experience() const { return _experience; }

    void loan(unsigned int amount) {
        _debt_amount += (amount + amount/10);
        _wealth_amount += amount;
    }

    unsigned int make_plush(unsigned int amount) {
        if(_wealth_amount > 0) {
            auto invested = std::min(amount, _wealth_amount);
            auto value = invested + std::max(_experience, _experience * invested / 100);

            _stock_size ++;
            _experience ++;

            _wealth_amount -= invested;

            _plushes.emplace_back(Plush{invested});
            
            return value;
        }
        return 0;
    }

    std::optional<Plush> buy(unsigned int amount) {
        
        std::optional<Plush> opt = std::nullopt;
        auto iterator = _plushes.begin();
        for(auto it = _plushes.begin() ; it != _plushes.end() ; it++) {
            auto p = *it;
            if(p.get_cost() <= amount && (opt == std::nullopt || p.get_cost() > opt.value().get_cost())) {
                opt = p;
                iterator = it;
                std::cout << p.get_cost() << std::endl;
            }
        }
        if(opt != std::nullopt) {
            _plushes.erase(iterator);
        }
        return opt;
    }

private:
    std::string _name;
    unsigned int _wealth_amount = 0;
    unsigned int _stock_size = 0;
    std::vector<Plush> _plushes;
    unsigned int _debt_amount = 0;
    unsigned int _experience = 0;
};

/*
qualité du code :
=> copies inutiles
=> const ref etc 

exercices indépendants :

1 er exercice : vector
2eme exercice : map
3eme exercice : string (+ classe)
*/