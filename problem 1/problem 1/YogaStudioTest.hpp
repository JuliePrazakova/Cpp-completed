#ifndef cpp_tst_priklad1_h
#define cpp_tst_priklad1_h

#include "TestSuite/Test.h"
#include "YogaStudio.hpp"

// 12 bodu
// U testu jednotlivych metod staci uvest pouze jeden
/// testovaci pripad. Jde o to ukazat myslenku testu.
/// V kazdem testu si nejprve pripravte studio s nejakymi lekcemi
/// a pak overte funkcnost dane metody.
class YogaStudioTest:public TestSuite::Test{
public:
    // 4 body
    void testGetEmptyLessons(){
        // 1. priprava dat
        Lesson lesson1(11, "hot90", "90 min hot yoga lekce", 90);
        Lesson lesson2(12, "yin", "yin yoga lekce", 100);
        Lesson lesson3(13, "vinyasa", "slow flow", 120);
        lesson3.addParticipants({"terka", 20, female});
        
        YogaStudio studio1;
        studio1.addLesson(lesson1);
        studio1.addLesson(lesson2);
        studio1.addLesson(lesson3);

        test_(studio1.getEmptyLessons().size() == 2);
        
    }
    
    // 4 body
    void testGetLessonsWithDurationInRange(){
        // 1. priprava dat
        YogaStudio yo;
        
        yo.addLesson({0, "timiassa", "blablabla", 3600});
        yo.addLesson({1, "hot yoga", "hihih", 6000});
        yo.addLesson({2, "tabata", "nonono", 5600});
        
        // 2. volani metody
        auto lessons = yo.getLessonsWithDurationInRange(2000, 5900);
        
        // 3. testovani
        test_(lessons.size() == 2);
        test_(lessons.at(0).getId() == 0);
        test_(lessons.at(1).getId() == 2);
        
//        Lesson lesson1(11, "hot90", "90 min hot yoga lekce", 90);
//        Lesson lesson2(12, "yin", "yin yoga lekce", 100);
//        Lesson lesson3(13, "vinyasa", "slow flow", 120);
//        lesson3.addParticipant(Participant{"terka", 20, female});
//
//        YogaStudio* studio1 = new YogaStudio("studio1");
//        studio1->addLesson(lesson1);
//        studio1->addLesson(lesson2);
//        studio1->addLesson(lesson3);
//
//        test_(studio1->getLessonsWithDurationInRange(100, 130).size() == 2);
        
    }
    
    // 4 body
    void testGetRatioOfManAndWoman() {
        // 1. priprava dat
        YogaStudio yo;
        yo.addLesson({0, "timiassa", "blablabla", 3600});
        yo.registerParticipant(0, {"Jan", 28, Gender::male });
        yo.registerParticipant(0, {"Jana", 37, Gender::female });
        
        // 2. volani metody
        auto ratio = yo.getRatioOfManAndWoman();
        
        // 3. testovani
        test_(ratio == 1);
        
        
//        Lesson lesson1(11, "hot90", "90 min hot yoga lekce", 90);
//        Lesson lesson2(12, "yin", "yin yoga lekce", 100);
//        Lesson lesson3(13, "vinyasa", "slow flow", 120);
//        lesson1.addParticipant(Participant{"petr", 20, male});
//        lesson2.addParticipant(Participant{"pavel", 20, male});
//        lesson3.addParticipant(Participant{"terka", 20, female});
//        lesson3.addParticipant(Participant{"samko", 20, male});
//        lesson3.addParticipant(Participant{"domca", 20, female});
//
//
//        YogaStudio* studio1 = new YogaStudio("studio1");
//        studio1->addLesson(lesson1);
//        studio1->addLesson(lesson2);
//        studio1->addLesson(lesson3);
//
//        std::cout << "ratio: " << studio1->getRatioOfManAndWoman() << std::endl;
//        test_(studio1->getRatioOfManAndWoman() == 3/2);
    }
    
    void run() override{
        testGetEmptyLessons();
        testGetLessonsWithDurationInRange();
        testGetRatioOfManAndWoman();
    }
};

#endif
