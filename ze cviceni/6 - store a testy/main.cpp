#include "Store.h"
#include "TestSuite/Suite.h"
#include "StoreTest.hpp"

int main() {
    // --- UNIT TESTS ---
    auto* suite = new TestSuite::Suite("Store Tests");
    suite->addTest(new StoreTest());
    suite->run();
    suite->report();
    delete suite;

    // --- MANUAL TESTING OF PRINTS ---
    auto store = new Store();

    store->addCustomer(1, 23, "Ivo", "Zemedelska 1");
    store->addCustomer(2, 33, "David", "Zemedelska 2");
    store->selectActiveCustomer(1);

    store->addItemToBasket(12, "Item A");
    store->addItemToBasket(20.3, "Item B");
    store->placeOrder();

    store->printBasketInfo();
    store->printAllCustomers();
    store->printDatesOfNewOrders();

    delete store;

    return 0;
}
