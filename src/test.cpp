#include "PlushStore.hpp"
#include <iostream>

int main() {

    auto plush_store = PlushStore { "Fluffy" };
    plush_store.loan(10);
    
    plush_store.make_plush(10);

    // La fonction buy doit renvoyer un objet de type std::optional<Plush>.

    const auto plush = plush_store.buy(50);
    std::cout << plush.value().get_cost() << std::endl;    
}

