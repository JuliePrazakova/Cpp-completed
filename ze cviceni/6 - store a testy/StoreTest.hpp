#ifndef StoreTest_hpp
#define StoreTest_hpp

#include "TestSuite/Test.h"

class StoreTest: public TestSuite::Test {
public:
    void run() override;
private:
    void testAddCustomer();
    void testAddCustomerInvalidArgument();

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

#endif /* StoreTest_hpp */
