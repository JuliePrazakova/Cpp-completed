//
//  RoverTest.hpp
//  7 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#ifndef RoverTest_hpp
#define RoverTest_hpp
#include "TestSuite/Test.hpp"


class RoverTest: public TestSuite::Test {
public:
    void run() override;
private:
    void testProcessMaterialInStorageWithIce();
    void testProcessMaterialInStorageWithSoil();
};

#endif /* RoverTest_hpp */
