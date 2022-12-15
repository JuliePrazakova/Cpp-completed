//
//  main.cpp
//  problem 1 od terky
//
//  Created by Julie Pražáková on 14.12.2022.
//

#include "TestSuite/Suite.h"
#include "YogaStudioTest.hpp"
#include "LessonTest.hpp"

int main (int argc, const char * argv[])
{
    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new LessonTest);
    tests.addTest(new YogaStudioTest);

    tests.run();
    tests.report();

//    print testing
//    Lesson lesson1(11, "hot90", "90 min hot yoga lekce", 90);
//    Lesson lesson2(12, "yin", "yin yoga lekce", 100);
//    Lesson lesson3(13, "vinyasa", "slow flow", 120);
//    lesson3.addParticipant(Participant{"terka", 20, female});
//
//    YogaStudio* studio1 = new YogaStudio("studio1");
//    studio1->addLesson(lesson1);
//    studio1->addLesson(lesson2);
//    studio1->addLesson(lesson3);
//    studio1->printTimetable("timetable.txt");

    return 0;
}
