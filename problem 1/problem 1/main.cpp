//
//  main.cpp
//  problem 1
//
//  Created by Julie Pražáková on 13.12.2022.
//

#include <iostream>
#include "TestSuite/Suite.h"
#include "YogaStudioTest.hpp"
#include "LessonTest.hpp"

int main (int argc, const char * argv[]){
//    YogaStudio* yo = new YogaStudio();
//    yo->addLesson({0, "timiassa", "blablabla", 3600});
//    yo->addLesson({1, "hot yoga", "hihih", 6000});
//    yo->addLesson({2, "tabata", "nonono", 5600});
//
//    yo->printTimetable("timetable.txt");
//

    TestSuite::Suite tests("Test semestralni zkousky C++");
   // tests.addTest(new LessonTest);
    tests.addTest(new YogaStudioTest);

   // tests.run();
   // tests.report();
    
   // delete yo;
    return 0;
}
