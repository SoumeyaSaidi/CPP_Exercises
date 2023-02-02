#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include "Plush.hpp"
#include <optional>
#include <functional>

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
        _debt_amount += (amount * 1.1);
        _wealth_amount += amount;
    }

    unsigned int make_plush(unsigned int amount) {
        if(_wealth_amount > 0) {
            auto invested = std::min(_wealth_amount, amount);
            auto value = invested + std::max(_experience, _experience * invested / 100);

            _experience++;
            _wealth_amount -= invested;
            _stock_size++;
            _plushes.emplace_back(value);

            return value;
        }
        return 0;
    }

    std::optional<Plush> buy(unsigned int money) {
        std::optional<Plush> plush = std::nullopt;
        auto it_res = _plushes.end();
        
        for(auto it = _plushes.begin() ; it != _plushes.end() ; ++it) {
            if(it->get_cost() <= money && (it_res == _plushes.end() || it->get_cost() < it_res->get_cost())) {
                it_res = it;
                plush = *it;
            }
        }
        if(it_res != _plushes.end()) {
            _stock_size--;
            _wealth_amount += it_res->get_cost();
            _plushes.erase(it_res);
        }
        return plush;
    }

private:
    std::string _name;
    unsigned int _wealth_amount = 0u;
    unsigned int _stock_size = 0u;
    unsigned int _debt_amount = 0u;
    unsigned int _experience = 0u;
    std::vector<Plush> _plushes;
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