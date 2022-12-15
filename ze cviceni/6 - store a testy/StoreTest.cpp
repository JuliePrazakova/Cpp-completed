#include "StoreTest.hpp"
#include "Store.h"
#include "CustomerException.h"

void StoreTest::run() {
    testAddCustomer();

    testAddCustomerInvalidArgument();

    testSelectActiveCustomer();
    testSelectActiveCustomerNotFound();
    testSelectActiveCustomerAlreadyActive();

    testAddItemToBasket();
    testEmptyBasket();
    
    testPlaceOrder();
    testPlaceOrderEmptyBasket();
    testPlaceOrderVIP();

    testSortCustomersByVipStatus();
}

void StoreTest::testAddCustomer() {
    // 1. prepare data
    Store store;

    // 2. call the tested method
    store.addCustomer(100, 23, "John", "Zemedelska 1");

    // 3. verify results
    auto customers = store.getCustomers();
    test_(customers.size() == 1);
    test_(customers.at(0).memberId == 100); // must also check the content of the vector, not just its size!
}

void StoreTest::testAddCustomerInvalidArgument() {
    // 1. prepare data
    Store store;

    // 2. call the tested method
    try {
        store.addCustomer(100, 23, "", "Zemedelska 1");
        fail_("The exception should be thrown because the name is empty.");
    } catch (std::invalid_argument e) {
        // 3. verify results
        test_(store.getCustomers().empty());
    }
}

void StoreTest::testSelectActiveCustomer() {
    // 1. prepare data
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");

    // 2. call the tested method
    store.selectActiveCustomer(1);

    // 3. verify results
    test_(store.getActiveCustomer()->memberId == 1);
}

void StoreTest::testSelectActiveCustomerNotFound() {
    // 1. prepare data
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");

    // 2. call the tested method
    try {
        store.selectActiveCustomer(2);
        fail_("The exception should be thrown because no customer with ID 2 exists.");
    } catch (std::out_of_range e) {
        // 3. verify results
        succeed_();
    }
}

void StoreTest::testSelectActiveCustomerAlreadyActive() {
    // 1. prepare data
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");
    store.selectActiveCustomer(1);

    // 2. call the tested method
    try {
        store.selectActiveCustomer(1);
        fail_("The exception should be thrown because the customer is already active.");
    } catch (CustomerException e) {
        // 3. verify results
        succeed_();
    }
}

void StoreTest::testAddItemToBasket() {
    // 1. prepare data
    Store store;

    // 2. call the tested method
    store.addItemToBasket(25600.00, "iPhone 13");
    store.addItemToBasket(29.90, "bread");

    // 3. verify results
    auto basket = store.getBasket();
    test_(basket.size() == 2);
    test_(basket.at(0).description == "iPhone 13");
    test_(basket.at(1).description == "bread");
}

void StoreTest::testEmptyBasket() {
    // 1. prepare data
    Store store;
    store.addItemToBasket(25600.00, "iPhone 13");
    store.addItemToBasket(29.90, "bread");

    // 2. call the tested method
    store.emptyBasket();

    // 3. verify results
    auto basket = store.getBasket();
    test_(basket.empty());
}

void StoreTest::testPlaceOrder() {
    // 1. prepare data
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");
    store.selectActiveCustomer(1);
    store.addItemToBasket(25600.00, "iPhone 13");
    store.addItemToBasket(29.90, "bread");

    // 2. call the tested method
    store.placeOrder();

    // 3. verify results
    auto orders = store.getOrders();
    auto lastOrder = orders.find(store.getActiveCustomer())->second;
    test_(orders.size() == 1);
    test_(lastOrder.items.size() == 2);
    test_(lastOrder.items.at(0).description == "iPhone 13");
    test_(lastOrder.items.at(1).description == "bread");
    test_(store.getActiveCustomer()->vipMember == false); // 4 orders are required to become a VIP
}


void StoreTest::testPlaceOrderVIP() {
    // 1. prepare data
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");
    store.selectActiveCustomer(1);

    // 2. call the tested method
    // 3. verify results
    store.addItemToBasket(25600.00, "iPhone 13");
    store.placeOrder();
    test_(store.getActiveCustomer()->vipMember == false); // not a VIP after one order

    store.addItemToBasket(25600.00, "iPhone 13");
    store.placeOrder();
    test_(store.getActiveCustomer()->vipMember == false);

    store.addItemToBasket(25600.00, "iPhone 13");
    store.placeOrder();
    test_(store.getActiveCustomer()->vipMember == false);

    store.addItemToBasket(25600.00, "iPhone 13");
    store.placeOrder();
    test_(store.getActiveCustomer()->vipMember == true); // finally a VIP after 4 orders
}

void StoreTest::testPlaceOrderEmptyBasket() {
    // 1. prepare data
    Store store;

    // 2. call the tested method
    try {
        store.placeOrder();
        fail_("Should throw an exception because the basket is empty.");
    } catch (StoreException e) {
        // 3. verify results
        test_(store.getOrders().empty());
    }
}

void StoreTest::testSortCustomersByVipStatus() {
    // 1. prepare data
    Store store;
    store.addCustomer(1, 23, "Cecilie", "Zemedelska 1");
    store.addCustomer(2, 23, "Beata", "Zemedelska 1");
    store.addCustomer(3, 23, "Antonin", "Zemedelska 1");

    // Beata have 4 orders and is a VIP
    store.selectActiveCustomer(2);
    store.addItemToBasket(1, "a");
    store.placeOrder();
    store.addItemToBasket(1, "a");
    store.placeOrder();
    store.addItemToBasket(1, "a");
    store.placeOrder();
    store.addItemToBasket(1, "a");
    store.placeOrder();

    // 2. call the tested method
    store.sortCustomersByVipStatus();

    // 3. verify results
    auto customers = store.getCustomers();
    test_(customers.at(0).name == "Beata"); // Beata is VIP and must be first
    test_(customers.at(1).name == "Antonin"); // Antonin is the second because A is before C
    test_(customers.at(2).name == "Cecilie");
}



