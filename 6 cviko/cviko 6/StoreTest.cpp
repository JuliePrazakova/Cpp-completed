#include "StoreTest.hpp"
#include "Store.h"
#include "CustomerException.h"


void StoreTest::run() {
    //tady vypiseme vsechno testy co chceme spustit
    testSelectActiveCustomer();
    testAddCustomerInvalidArguments();
    
    testAddCustomer();

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

// 1. priprava dat = udelame store
// 2. volani metody
// 3. overeni vysledku = tady volame test_
//nezapomenout mazat objekty!

void StoreTest::testSelectActiveCustomer(){
    // 1. priprava dat = udelame store a pridame 2 zakazniky
    auto store = new Store();
    store->addCustomer(1, 20, "Jan", "Zemedelska 12");
    store->addCustomer(2, 34, "Ales", "Zimni stadion 12");
    
    // 2. volani metody
    store->selectActiveCustomer(2);
    
    // 3. overeni vysledku = tady volame test_
    test_(store->getActiveCustomer()->memberId == 2);
    
    //nezapomenout mazat objekty!
    delete store;
}
void StoreTest::testSelectActiveCustomerNotFound(){
    //1. priprava dat
    Store store;
    store.addCustomer(1, 20, "Jan", "Zemedelska 12");
    
    //2. volani metody
    try{
        store.selectActiveCustomer(2); //neexistuje
        fail_("should be throwing an exception because customer with this memberId does not exist");
    }catch (std::out_of_range e) {
        //3. overeni vysledku
        succeed_();
    }
}
void StoreTest::testSelectActiveCustomerAlreadyActive(){
    //1. priprava dat
    Store store;
    store.addCustomer(1, 20, "Jan", "Zemedelska 12");
    store.selectActiveCustomer(1);
    
    //2. volani metody
    try{
        store.selectActiveCustomer(1);
        fail_("should be throwing an exception because this customer is already active");
    }catch (CustomerException e) {
        //3. overeni vysledku
        succeed_();
    }
}

void StoreTest::testAddCustomerInvalidArguments(){
    //1. priprava dat
    Store store;
    
    //2. volani metody
    //3. overeni vysledku
    try{
        store.addCustomer(-1, -20, "", "Zemedelska 12");
        fail_("should be throwing an exception because the customer info is invalid");
    }catch (std::invalid_argument e) {
        succeed_();
    }
}

void StoreTest::testAddCustomer(){
    // 1. priprava dat = udelame store
    auto store = new Store();
    
    // 2. volani metody
    store->addCustomer(1, 20, "Jan", "Pod Zamkem 1122");
    
    // 3. overeni vysledku = tady volame test_
    //jednodussi zpusob:
        // a. prekopirujeme VSECHNY customery sem
    auto customer = store->getCustomers();
        // b. zmerime velikost vectoru = jestli jich neni vic
    test_(customer.size() == 1);
        // c. overime ze ma stejne ID
    test_(customer.at(0).memberId == 1);
    
    //nezapomenout mazat objekty!
    delete store;
}
// 1. priprava dat = udelame store
// 2. volani metody
// 3. overeni vysledku = tady volame test_
//nezapomenout mazat objekty!



void StoreTest::testAddItemToBasket(){
    // 1. priprava dat = udelame store
    Store store;
    
    // 2. volani metody
    store.addItemToBasket(2000, "Sedacka");
    store.addItemToBasket(100, "Zidle");
    
    // 3. overeni vysledku = tady volame test_
    auto basket = store.getBasket();
    test_(basket.size() == 2);
    test_(basket.at(0).description == "Sedacka");
    test_(basket.at(1).description == "Zidle");
}
void StoreTest::testEmptyBasket(){
    // 1. priprava dat = udelame store
    Store store;
    store.addItemToBasket(2000, "Sedacka");
    
    // 2. volani metody
    store.emptyBasket();
    
    // 3. overeni vysledku = tady volame test_
    auto basket = store.getBasket();
    test_(basket.empty());
}

void StoreTest::testPlaceOrder(){
    // 1. priprava dat = udelame store
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");  //customer
    store.selectActiveCustomer(1);
    store.addItemToBasket(2000, "Sedacka");  //itemy do basketu
    store.addItemToBasket(29.90, "bread");

    // 2. volani metody
    store.placeOrder();

    // 3. overeni vysledku = tady volame test_
    auto orders = store.getOrders();

    auto lastOrder = orders.find(store.getActiveCustomer())->second; //bacha musime posilat ukazatel (*) z getActiveCustomer!
    test_(lastOrder.items.size() == 2); // obsahovala 2 polozky
    test_(lastOrder.items.at(0).description == "Sedacka");
    test_(lastOrder.items.at(1).description == "bread");
}
void StoreTest::testPlaceOrderEmptyBasket(){
    // 1. priprava dat = udelame store
    Store store;
    
    try{
        // 2. volani metody
        store.placeOrder();
        fail_("should be throwing an exception because basket is empty");
    }catch (StoreException e){
        succeed_();
        test_(store.getOrders().empty()); //kontrola, ze je basket fakt empty
    }
}
void StoreTest::testPlaceOrderVIP(){
    // 1. priprava dat = udelame store
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");  //customer
    store.selectActiveCustomer(1);
    store.addItemToBasket(2000, "Sedacka");  //item do basketu
    
    // 2. volani metody
    store.placeOrder(); // 1
    test_(store.getActiveCustomer()->vipMember == false); // not a VIP yet

    store.addItemToBasket(2000, "Sedacka");  //itemy do basketu
    store.placeOrder(); // 2
    test_(store.getActiveCustomer()->vipMember == false); // not a VIP yet
    store.addItemToBasket(2000, "Sedacka");  //itemy do basketu
    store.placeOrder(); // 3
    test_(store.getActiveCustomer()->vipMember == false); // not a VIP yet

    store.addItemToBasket(2000, "Sedacka");  //itemy do basketu
    store.placeOrder(); // 4 = ma byt VIP
    test_(store.getActiveCustomer()->vipMember == true); // mel by byt VIP
    
}

void StoreTest::testSortCustomersByVipStatus(){
    // 1. priprava dat = udelame store
    Store store;
    store.addCustomer(1, 23, "John", "Zemedelska 1");
    store.addCustomer(2, 21, "Lukas", "Doma");
    store.addCustomer(3, 22, "Adam", "Kaminky 1");
    
    // Lukas has 4 orders and is a VIP
       store.selectActiveCustomer(2);
       store.addItemToBasket(1, "a");
       store.placeOrder();
       store.addItemToBasket(1, "a");
       store.placeOrder();
       store.addItemToBasket(1, "a");
       store.placeOrder();
       store.addItemToBasket(1, "a");
       store.placeOrder();
    
    // 2. volani metody
    store.sortCustomersByVipStatus();

    // 3. verify results
    auto customers = store.getCustomers();
    test_(customers.at(0).name == "Lukas"); // Lukas je VIP = prvni
    test_(customers.at(1).name == "Adam"); // Adam je druhy protoze A je pred C
    test_(customers.at(2).name == "John");
    
}
