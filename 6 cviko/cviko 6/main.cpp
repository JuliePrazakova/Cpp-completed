//
//  main.cpp
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include <iostream>
#include "Store.h"
#include "Suite.h"
#include "StoreTest.hpp"

int main(int argc, const char *argv[]) {
    auto* suite = new TestSuite::Suite("Map Tests");

    suite->addTest(new StoreTest());

    suite->run();
    suite->report();

    delete suite;


    return 0;
}

