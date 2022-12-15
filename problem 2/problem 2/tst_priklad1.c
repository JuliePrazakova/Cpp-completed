//
//  tst_priklad1.c
//  problem 2
//
//  Created by Julie Pražáková on 14.12.2022.
//

#include "tst_priklad1.h"

void TestPrikladu1::testCandidate(){
    // 1. priprava dat
    BallotList bal;
    
    // 2. volani metody
    auto list = bal.getCandidatesBallots(Candidate::DonaldTrump);
    
    // 3. test
    test_(list.size() == 3);

}
void TestPrikladu1::run(){
    testCandidate();
    testValid();
}

void TestPrikladu1::testValid(){
    // 1. priprava dat
    BallotList bal;
    
    // 2. volani metody
    auto list = bal.getBallots(State::Invalid);

    // 3. test
    test_(list.size() == 1);
}
