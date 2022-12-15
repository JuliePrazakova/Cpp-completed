//
//  main.cpp
//  problem 4
//
//  Created by Julie Pražáková on 15.12.2022.
//

#include <iostream>
#include "TicketTest.h"
#include "IceSkatingRinkTest.h"

int main(int argc, const char * argv[])
{
//    TestSuite::Suite tests("Test semestralni zkousky C++");
//
//    tests.addTest(new TicketTest());
//    tests.addTest(new IceSkatingRinkTest());
//
//    tests.run();
//    tests.report();
    Ticket* t = new Ticket(0, 150, TicketState::Bought, "2022-10-01");
    t->printToFile("ticket.txt");
    
    delete t;
    return 0;
}
