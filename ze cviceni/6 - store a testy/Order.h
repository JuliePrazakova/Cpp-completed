//
//  Order.h
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef CPP_cviceni6_obchod_Order_h
#define CPP_cviceni6_obchod_Order_h

#include <vector>
#include <chrono>
#include "Item.h"

/**
 Jedna objednavka, ktera obsahuje seznam nakoupeneho zbozi
 a ukazatel na zakaznika
*/

enum class OrderStatus {
    New, Approved, Delivered, Closed, Cancelled
};

struct Order {
    std::chrono::time_point<std::chrono::system_clock> time;
    std::vector<Item> items;
    OrderStatus status;
};

#endif
