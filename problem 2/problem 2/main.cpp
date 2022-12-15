//
//  main.cpp
//  problem 2
//
//  Created by Julie Pražáková on 14.12.2022.
//

#include <iostream>

#include "priklad1.h"
#include "priklad2.h"

#include "tst_priklad1.h"

int main(int argc, const char * argv[]) {
    auto* suite = new TestSuite::Suite("Test semestralni zkousky C++");
    suite->addTest(new TestPrikladu1());
//
//    tests.run();
//    tests.report();
//    BallotList* bal = new BallotList();
//
//    delete bal;
    
    delete suite;
    return 0;
}
