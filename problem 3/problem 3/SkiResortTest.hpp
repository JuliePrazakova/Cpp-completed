#ifndef cpp_tst_priklad1_h
#define cpp_tst_priklad1_h

#include "TestSuite/Test.h"
#include "SkiResort.hpp"

// 12 bodu
/// U testu jednotlivych metod staci uvest pouze jeden
/// testovaci pripad. Jde o to ukazat myslenku testu.
/// V kazdem testu si nejprve pripravte studio s nejakymi lekcemi
/// a pak overte funkcnost dane metody.
class SkiResortTest: public TestSuite::Test{
public:
    // 4 body
    void testGetRatioOfCovidPositiveGuests(){
        // 1. pripravit data
        SkiResort* resort = new SkiResort();
        Guest guest1(100, "sam", 27, "negativni");
        Guest guest2(101, "perda", 20, "pozitivni covid 19");
        Guest guest3(102, "ali", 12, "negativni");
        Guest guest4(103, "panda", 10, "pozitivni na covid19");
        Guest guest5(104, "seal", 30, "pozitivni na covid 2019");
        Guest guest6(105, "terda", 8, "pozitivni na covid2019");
        Guest guest7(106, "elda", 50, "covid2019");
        Guest guest8(107, "freda", 5, "COVID 19");
        resort->addGuest(guest1);
        resort->addGuest(guest2);
        resort->addGuest(guest3);
        resort->addGuest(guest4);
        resort->addGuest(guest5);
        resort->addGuest(guest6);
        resort->addGuest(guest7);
        resort->addGuest(guest8);

        // 3. testovat
        test_(resort->getRatioOfCovidPositiveGuests() == 75);
    }
    
    // 4 body
    void testGetSortedGuests(){
        // 1. pripravit data
        SkiResort ski;
        
        ski.addGuest({0, "Janek", 3, "blablabalCovid19"});
        ski.addGuest({1, "Mark", 7, "Covid19"});
        ski.addGuest({2, "Darek", 25, "nic"});
        
        // 2. zavolat metodu
        auto sorted = ski.getSortedGuests();
        
        // 3. testovat
        test_(sorted.at(0).getId() == 1);
        test_(sorted.at(0).getName().at(0) == 'M');
        test_(sorted.at(1).getId() == 0);
        test_(sorted.at(2).getId() == 2);
    }
    
    // 4 body
    void testGetCountOfChildren() {
        // 1. pripravit data
        SkiResort ski;
        
        ski.addGuest({0, "Janek", 3, "blablabalCovid19"});
        ski.addGuest({1, "Mark", 7, "Covid19"});
        ski.addGuest({2, "Darek", 25, "nic"});
        
        // 2. zavolat metodu
        auto children = ski.getCountOfChildren();
        
        // 3. testovat
        test_(children == 2);
    }
    
    void run(){
        testGetRatioOfCovidPositiveGuests();
        testGetSortedGuests();
        testGetCountOfChildren();
    }
};

#endif
