//
//  main.cpp
//  problem 3
//
//  Created by Julie Pražáková on 14.12.2022.
//

#include "TestSuite/Suite.h"
#include "GuestTest.hpp"
#include "SkiResortTest.hpp"

int main (int argc, const char * argv[])
{
//    TestSuite::Suite tests("Test semestralni zkousky C++");
//    tests.addTest(new GuestTest);
//    tests.addTest(new SkiResortTest);
//
//    tests.run();
//    tests.report();
    
    SkiResort ski;
    
    ski.addGuest({0, "Janek", 37, "blablabalCovid19"});
    ski.addGuest({1, "Mark", 7, "Covid19"});
    ski.addGuest({2, "Darek", 25, "nic"});
    ski.printTicket({2, "Darek", 5, "nic"});
    
    return 0;
}
