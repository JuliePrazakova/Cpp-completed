//
//  main.cpp
//  4 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#include <iostream>
#include "Game.hpp"
#include "MapTest.hpp"
#include "Suite.hpp"


int main(int argc, const char * argv[]) {
    
// NORMALNI spusteni aplikace
//    Game* game = new Game();
//    game->start();

// TESTOVANI
    auto* suite = new TestSuite::Suite("Map Tests");

    suite->addTest(new MapTest());

    suite->run();
    suite->report();

    delete suite;
    
    return 0;
}
