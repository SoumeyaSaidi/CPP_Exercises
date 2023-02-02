#pragma once

#include <string>
#include <algorithm>
#include <set>
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
        _wealth_amount += amount;
        _debt_amount += (amount * 1.1);
    }

    unsigned int make_plush(unsigned int amount) {
        if(_wealth_amount > 0) {
            auto price = std::min(_wealth_amount, amount);
            auto finalValue = price + std::max(_experience, _experience * price / 100);

            _experience++;
            _wealth_amount -= price;
            _stock_size++;
            _plushes.emplace(finalValue);
            return finalValue;
        }
        return 0;
    }

    std::optional<Plush> buy(unsigned int amount) {
        for(const auto& plush : _plushes) {
            if(plush.get_cost() <= amount) {
                _plushes.erase(plush);
                _stock_size--;
                _wealth_amount += plush.get_cost();
                return std::optional{plush};
            }
        }
        return std::nullopt;
    }

private:
    const std::string _name;
    unsigned int _wealth_amount = 0u;
    unsigned int _stock_size = 0u;
    unsigned int _debt_amount = 0u;
    unsigned int _experience = 0u;
    std::set<Plush> _plushes;
};