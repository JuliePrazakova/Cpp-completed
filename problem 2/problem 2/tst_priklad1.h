#ifndef TST_PRIKLAD1_H
#define TST_PRIKLAD1_H

#include "Suite.h"
#include "Test.h"
#include "priklad1.h"

/// Testy: 10 b
/// Oba testy ukazte na kratky prikladech napr. 3-5 volebnich listku
class TestPrikladu1: public TestSuite::Test {
public:
    void run() override;
    
private:
    /// otestujte, zda se povedlo vratit zaznamy daneho kandidata - 5 b
    void testCandidate();

    /// otestujte, zda se korektne vraci listky daneho typu - 5 b
    void testValid();
    
};
#endif // TST_PRIKLAD1_H
