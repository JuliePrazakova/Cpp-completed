#include "MapTest.hpp"

void MapTest::run() {
    testMoveTesla();
    testCheckDirection();
}

void MapTest::testMoveTesla() {
    // vytvoreni instance, priprava dat
    Map map;
    
    // neco provedu, zavolam metodu
    map.moveTesla(-1, 0);
    
    // overim, ze Tesla mi neprepsala mapu
    test_(map.getField(2, 3) == '-');
    
    // overim, ze se zmenila X pozice Tesly o -1 (doleva)
    test_(map.getTesla()->getX() == 2);
    test_(map.getTesla()->getY() == 3);
}

void MapTest::testCheckDirection() {
    // 1. priprava dat a trid
    Map map;
    
    // 2. neco zavolam
    bool collision = map.checkDirection(-1, 0);
    // 3. overim vystupy
    test_(collision == true);

    // 2. neco zavolam
    bool collision2 = map.checkDirection(-1000, 0);
    // 3. overim vystupy
    test_(collision2 == false);
}
