#ifndef cpp_tst_priklad2_h
#define cpp_tst_priklad2_h

#include "TestSuite/Test.h"
#include "Lesson.hpp"

// 4 body
class LessonTest:public TestSuite::Test{
private:
    // 2 bod
    /// Overte, ze pri vytvoreni objektu Lesson se spravnymi parametry se nevyhodi vyjimka.
    void testValidParameters(){
        try {
            Lesson* lesson1 = new Lesson(1, "samous2", "content", 300);
            succeed_();
        } catch(std::exception e) {
            fail_("Vyjimka vyhozena");
        }
    }
    
    // 2 bodu
    /// Overte, ze pri vytvoreni objektu Lesson s nespravnymi parametry se vyhodi vyjimka.
    void testInvalidParameters(){
        try {
            Lesson* lesson1 = new Lesson(1, "2samous2", "", 0);
            fail_("Vyjimka vyhozena");
        } catch(std::exception e) {
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
