#pragma once

class Plush {

public:
    Plush(){}
    
    Plush(unsigned int cost)
    : _cost{cost}
    {}

    unsigned int get_cost() const { return _cost; }

    void set_cost(unsigned int cost) { _cost = cost; }

    bool operator<(const Plush& other) const {
        return _cost < other._cost;
    }

private:
    unsigned int _cost = 10u;
};