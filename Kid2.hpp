#pragma once

#include <string>
#include <ostream>
#include <optional>
#include "PlushStore.hpp"

class Kid {

public:
    Kid(const std::string& name, unsigned int money)
    : _name{name}, _money{money}
    {}

    const std::string& get_name() const { return _name; }
    unsigned int get_money() const { return _money; }

    void buy_plush(PlushStore& store) {
        const auto plush = store.buy(_money);
        if(plush != std::nullopt) {
            _money -= plush->get_cost();
        }
    }

private:
    std::string _name;
    unsigned int _money;
};

std::ostream& operator<<(std::ostream& stream, const Kid& kid) {
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}