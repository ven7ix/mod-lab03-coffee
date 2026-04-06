// Copyright 2026 Andrew

#include "Automata.h"
#include <iostream>

int main() {
    Automata automata;

    std::cout << automata.get_state() << std::endl;

    automata.on();
    std::cout << automata.get_state() << std::endl;

    automata.coin(50);
    std::cout << automata.get_state() << std::endl;
    automata.cancel();
    std::cout << automata.get_state() << std::endl;
    automata.coin(10);
    std::cout << automata.get_state() << std::endl;
    automata.coin(1);
    std::cout << automata.get_state() << std::endl;

    automata.choice(1);
    std::cout << automata.get_state() << std::endl;
    automata.cancel();
    std::cout << automata.get_state() << std::endl;

    automata.coin(0);
    std::cout << automata.get_state() << std::endl;
    automata.choice(2);
    std::cout << automata.get_state() << std::endl;
    automata.check();
    std::cout << automata.get_state() << std::endl;
    return 0;
}
