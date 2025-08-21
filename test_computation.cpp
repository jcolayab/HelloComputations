#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "Computation.hpp"

TEST_CASE("Computation::add works correctly", "[add]") {
    Computation comp;
    REQUIRE(comp.add(2, 3) == 5);
    REQUIRE(comp.add(-1, 1) == 0);
}

TEST_CASE("Computation::subtract works correctly", "[subtract]") {
    Computation comp;
    REQUIRE(comp.subtract(2, 3) == -1);
    REQUIRE(comp.subtract(-1, 1) == -2);
}
