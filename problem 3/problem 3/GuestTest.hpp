#ifndef cpp_tst_priklad2_h
#define cpp_tst_priklad2_h

#include "TestSuite/Test.h"
#include "Guest.hpp"

// 4 body
class GuestTest: public TestSuite::Test{
private:
    // 2 bod
    /// Overte, ze pri vytvoreni objektu Guest se spravnymi parametry se nevyhodi vyjimka.
    void testValidParameters(){
        try{
            Guest g = {1, "Janek", 23, "covid19"};
            succeed_();
        }catch(std::invalid_argument e){
            fail_("test neprosel, protoze se vyhodila vyjimka");
        }  
    }
    
    // 2 bodu
    /// Overte, ze pri vytvoreni objektu Guest s nespravnymi parametry se vyhodi vyjimka.
    void testInvalidParameters(){
        try{
            Guest g = {-1, "", -23, "covid19"};
            fail_("test neprosel, protoze se NEvyhodila vyjimka");
        }catch(std::invalid_argument e){
            succeed_();
        }
    }
    
public:
    void run(){
        testValidParameters();
        testInvalidParameters();
    }
};
#endif
