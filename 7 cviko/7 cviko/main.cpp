//
//  main.cpp
//  7 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#include <iostream>
#include "Rover.hpp"
#include "materials/Ice.h"
#include "materials/Water.h"
#include "tests/TestSuite/Suite.hpp"
#include "tests/RoverTest.hpp"

int main(int argc, const char * argv[]) {
//  TESTOVANI
    auto* suite = new TestSuite::Suite("Rover Tests");
    auto* roverTest = new RoverTest();
    suite->addTest(roverTest);
    suite->run();
    suite->report();

    delete roverTest;
    delete suite;
    
//    auto rover = new Rover<Ice, Water>();
//   ICE
//       Ice ice1{1.2, -62.5};
//       rover->addParcel(ice1);
//       Ice ice2{0.9, -65.5};
//       rover->addParcel(ice2);
//       rover->printParcels();
    
//   SOIL
//       Soil soil1{4.05, "stone"};
//       rover->loadMaterial(soil1);
//       Soil soil2{2.8, "stone,sand"};
//       rover->loadMaterial(soil2);
//       rover->printStorageInfo();
    
//    delete rover;
    return 0;
}
