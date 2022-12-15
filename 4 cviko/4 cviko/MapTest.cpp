//
//  MapTest.cpp
//  4 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#include "MapTest.hpp"
#include "Maze.hpp"

void MapTest::run(){
    testMoveTesla();
    testCheckDirection();
}
void MapTest::testMoveTesla(){
    // 1. priprava dat
    Maze maze;
    
    // 2. volani funkce
    maze.moveTesla(-1, 0);

    // 3. testovani vysledku
        // overim, ze Tesla mi neprepsala mapu
    test_(maze.getField(2, 3) == '-');
    
        // overim, ze se zmenila X pozice Tesly o -1 (doleva)
    test_(maze.getTesla()->getX() == 2);
    test_(maze.getTesla()->getY() == 3);
}
void MapTest::testCheckDirection(){
    // 1. priprava dat
    Maze maze;
    
    // 2. volani funkce co musi byt TRUE
    bool collision = maze.checkDirection(-1, 0);
    
    // 3. testovani vysledku
    test_(collision == true);
    
    // 2. volani funkce co musi byt FALSE
    bool collision2 = maze.checkDirection(-10000, 0);
    
    // 3. testovani vysledku
    test_(collision2 == false);
}
