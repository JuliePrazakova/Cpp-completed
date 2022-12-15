#ifndef TST_PRIKLAD1_H
#define TST_PRIKLAD1_H

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "IceSkatingRink.hpp"

/// Testy: 12 b
class IceSkatingRinkTest: public TestSuite::Test {
public:
    
    /// Otestujte zmenu stavu listku po odchodu z kluziste.
    /// Otestujte happy i sad scenar (vyhozeni vyjimky).
    /// 4b
    void testExitRink() {}
    
    /// Otestujte ze metoda spravne vyfiltruje listky.
    /// Budte zakerni a kriticky metodu otestujte (pripravte si ruznorodou kolekci listku na vstup).
    /// 4b
    void testGetAllChildEnteredTickets() {}
    
    /// Otestujte ze metoda spravne vyfiltruje listky.
    /// Budte zakerni a kriticky metodu otestujte (pripravte si ruznorodou kolekci listku na vstup).
    /// 4b
    void testGetAllTicketsFrom() {}

    void run(){
        testExitRink();
        testGetAllChildEnteredTickets();
        testGetAllTicketsFrom();
    }
    
};
#endif // TST_PRIKLAD1_H
