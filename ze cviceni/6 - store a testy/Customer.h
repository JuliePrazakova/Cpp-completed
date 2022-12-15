//
//  Zakaznik.h
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef CPP_cviceni6_obchod_Customer_h
#define CPP_cviceni6_obchod_Customer_h

#include <iostream>

/**
 Zakaznik objednavajici si zbozi
 */
struct Customer {
    int memberId;
    float age;
    bool vipMember;
    std::string name;
    std::string address;
};

#endif
