#ifndef StoreTest_hpp
#define StoreTest_hpp

#include "TestSuite/Test.h"

class RoverTest: public TestSuite::Test {
public:
    void run() override;
private:
    void testProcessMaterialInStorageWithIce();
    void testProcessMaterialInStorageWithSoil();
};

#endif /* StoreTest_hpp */
