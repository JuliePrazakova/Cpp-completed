#ifndef MapTest_hpp
#define MapTest_hpp

#include "Test.h"

//piseme testy prakticky na vsechny funkce z Store.hpp
//jedine co netestujeme = print funkce = nema to smysl, nejde otestovat

class StoreTest: public TestSuite::Test {
public:
    void run() override;
private:
    void testAddCustomer();
    void testAddCustomerInvalidArguments();

    void testSelectActiveCustomer();
    void testSelectActiveCustomerNotFound();
    void testSelectActiveCustomerAlreadyActive();

    void testAddItemToBasket();
    void testEmptyBasket();

    // void testPrintBasketInfo(); -- cannot be tested, it does neither return anything nor it changes the object's state

    void testPlaceOrder();
    void testPlaceOrderEmptyBasket();
    void testPlaceOrderVIP();

    // void testPrintAllCustomers(); -- cannot be tested, it does neither return anything nor it changes the object's state
    // void testPrintDatesOfNewOrders(); -- cannot be tested, it does neither return anything nor it changes the object's state

    void testSortCustomersByVipStatus();
};

#endif /* MapTest_hpp */
