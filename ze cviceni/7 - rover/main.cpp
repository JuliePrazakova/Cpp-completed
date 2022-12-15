#include "tests/TestSuite/Suite.h"
#include "tests/RoverTest.hpp"

int main() {
    auto* suite = new TestSuite::Suite("Rover Tests");
    auto* roverTest = new RoverTest();
    suite->addTest(roverTest);
    suite->run();
    suite->report();

    delete roverTest;
    delete suite;

    return 0;
}
