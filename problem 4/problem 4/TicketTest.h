//
//  TicketTest.h
//  cpp_exam
//
//  Created by Ivo Pisařovic on 08.01.2022.
//

#ifndef TicketTest_h
#define TicketTest_h

#include "TestSuite/Suite.h"
#include "TestSuite/Test.h"
#include "Ticket.hpp"

/*
 5b
 */

class TicketTest: public TestSuite::Test {
public:
    
    /// otestujte, zda se povedlo vypsat info o tiketu na konec zadaneho souboru
    /// 5 b
    void testPrintToFile() {
        Ticket* t = new Ticket(0, 150, TicketState::Bought, "2022-10-01");
        t->printToFile("ticket.txt");
        
        test_(t->getLastLine("ticket.txt") == "ID: 0 Price: 150 State: Brought Date: 2022-10-01");
    }

    void run(){
        testPrintToFile();
    }
    
};



#endif /* TicketTest_h */
