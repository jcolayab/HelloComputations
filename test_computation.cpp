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

TEST_CASE("addCoverage covers all branches", "[coverage]") {
    Computation comp;
    SECTION("Both inputs positive") {
        REQUIRE(comp.addCoverage(2, 3) == 5); // hits true branch
    }
    SECTION("One or both inputs non-positive") {
        REQUIRE(comp.addCoverage(-1, 3) == 0); // hits false branch
        REQUIRE(comp.addCoverage(0, 0) == 0);  // hits false branch
    }
}

TEST_CASE("subtractCoverage covers all branches", "[coverage]") {
    Computation comp;
    SECTION("Both inputs positive") {
        REQUIRE(comp.subtractCoverage(10, 4) == 6); // hits true branch
    }
    SECTION("One or both inputs non-positive") {
        REQUIRE(comp.subtractCoverage(-1, 4) == 0); // hits false branch
        REQUIRE(comp.subtractCoverage(0, 0) == 0);  // hits false branch
    }
}

