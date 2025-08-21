#include <iostream>
#include "Computation.hpp"

int main() {
    Computation comp;

    const int addition = comp.add(4, 5);
    const int subtration = comp.add(6,7);

    std::cout << addition << std::endl;
    std::cout << subtration << std::endl;
}