//
//  MapTest.hpp
//  4 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#ifndef MapTest_hpp
#define MapTest_hpp

#include <stdio.h>

#include "Test.hpp"
#include "Maze.hpp"

class MapTest: public TestSuite::Test {
public:
    void run() override;
private:
    void testMoveTesla();
    void testCheckDirection();
};

#endif /* MapTest_hpp */
