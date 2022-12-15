#include "Game.h"
#include "TestSuite/Suite.h"
#include "MapTest.hpp"

int main() {
//    Game* game = new Game();
//    game->start();
    
    auto* suite = new TestSuite::Suite("Map Tests");

    suite->addTest(new MapTest());

    suite->run();
    suite->report();

    delete suite;
    
    return 0;
}
