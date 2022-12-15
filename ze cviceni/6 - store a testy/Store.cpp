//
//  Store.cpp
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "Store.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include "CustomerException.h"


Store::Store() {
}


void Store::addCustomer(const int memberId, const float age,
                        const std::string name, const std::string address) {
    if (
            memberId < 0 ||
            age < 0 ||
            name.empty() ||
            address.empty()
            ) {
        throw std::invalid_argument("All arguments must be nonnegative numbers and nonempty strings.");
    }

    m_customers.push_back(Customer{memberId, age, false, name, address});
}

void Store::selectActiveCustomer(const int memberId) {
    /* Klasicky pristup: */
//    for (int i = 0; i < m_customers.size(); i++) {
//        if (m_customers.at(i).memberId == memberId) {
//            m_activeCustomer = m_customers.at(i);
//            return;
//        }
//    }
//    throw std::out_of_range("Customer not found");

    /* Moderni pristup */
    // std::vector<Customer>::iterator
    auto it = std::find_if(
            m_customers.begin(),
            m_customers.end(),
            [memberId](const Customer &cus) -> bool {
                return cus.memberId == memberId;
            });

    if (it == m_customers.end()) {
        throw std::out_of_range("Customer not found");
    } else if (it == m_activeCustomer) {
        throw CustomerException("This customer is already active!", memberId);
    } else {
        m_activeCustomer = it;
    }
}

void Store::addItemToBasket(const float price, const std::string description) {
    m_basket.push_back(Item{description, price});
}

void Store::emptyBasket() {
    m_basket.clear();
}

void Store::printBasketInfo() {
    std::cout << "Aktualni zakaznik je " << (*m_activeCustomer).name /* NEBO m_activeCustomer->name */ << std::endl;

    for_each(
            m_basket.begin(),
            m_basket.end(),
            [](const Item &it) -> void {
                std::cout << "Popis: " << it.description << "\tcena: " <<
                std::fixed << std::setprecision(2) << it.price << " EUR" << std::endl;
            });
}

void Store::placeOrder() {
    if (m_basket.empty()) {
        throw StoreException("Your basket is empty.");
    }

    Order newOrder;
    newOrder.time = std::chrono::system_clock::now();

    newOrder.items.resize(m_basket.size());
    std::copy(m_basket.begin(), m_basket.end(), newOrder.items.begin());

    newOrder.status = OrderStatus::New;

    Customer* targetCustomer = &(*m_activeCustomer); // unwrap iterator and create a reference to the Customer
    m_orders.insert(std::pair<Customer *, Order>(targetCustomer, newOrder));

    emptyBasket();
    setVipStatus();
}

void Store::sortCustomersByVipStatus() {
    // sort by name
    sort(m_customers.begin(), m_customers.end(),
         [](const Customer &c1, const Customer &c2) -> bool {
             return c1.name > c2.name;
         });

    // sort by VIP status, stable = keep order of customers with equal VIP status
    stable_sort(m_customers.begin(), m_customers.end(),
         [](const Customer &c1, const Customer &c2)->bool{
             if ((c1.vipMember and !c2.vipMember) || (c1.vipMember == c2.vipMember)) {
                 return true; // if the first is VIP and the second is not or both are equal, then their order is ok and we should return true
             } else {
                 return false; // the order of c1 and c2 is not correct, swap them
             }
         });
}

void Store::printAllCustomers() const {
    for_each(m_customers.begin(), m_customers.end(),
             [](const Customer &cus) -> void {
                 std::cout << "Jmeno: " << cus.name << "\tvek:" << cus.age
                           << "\tvip: " << cus.vipMember << std::endl;
             });
}


void Store::printDatesOfNewOrders() {
//    int i = 0;
    for_each(m_orders.begin(), m_orders.end(),
             [/*&i*/](const std::pair<Customer *, Order> &pair) /*throw (std::out_of_range)*/ -> void {
                 if (pair.second.status == OrderStatus::New) {
//                     std::time_t yesterday = std::chrono::system_clock::to_time_t(
//                             pair.second.time - std::chrono::hours(24)); // odečti 24 hodin od nějakého času
                    std::time_t time = std::chrono::system_clock::to_time_t(pair.second.time);
                    std::cout << std::ctime(&time);
                 }
//                 if (i == 1) {
//                     throw std::out_of_range("jsem mimo");
//                 }
//                 i += 1;
             });
}

void Store::setVipStatus() {
    Customer* customer = &(*m_activeCustomer); // unwrap iterator and create a reference to the Customer
    auto range = m_orders.equal_range(customer); // get all orders for the given customer
    long count = std::distance(range.first, range.second); // count how many orders are there

    // alternative:
//    int count = 0;
//    for (auto & m_order : m_orders) {
//        if (m_order.first->memberId == m_activeCustomer->memberId) {
//            count++;
//        }
//    }

    if (count > 3) {
        m_activeCustomer->vipMember = true;
    }
}

std::vector<Customer> Store::getCustomers() const {
    return m_customers;
}

Customer* Store::getActiveCustomer() const {
    return &(*m_activeCustomer); // unwrap iterator and create a reference to the Customer
}

std::vector<Item> Store::getBasket() const {
    return m_basket;
}

std::multimap<Customer *, Order> Store::getOrders() const {
    return m_orders;
}







