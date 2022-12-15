//
//  main.cpp
//  problem 2 od terky
//
//  Created by Julie Pražáková on 14.12.2022.
//

#include <iostream>
#include "priklad1.h"
#include "priklad2.h"

#include "tst_priklad1.h"

int main(int argc, const char * argv[]) {
    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new TestPrikladu1);
    
    tests.run();
    tests.report();

    BallotList* ballot = new BallotList();
    
    return 0;
}
