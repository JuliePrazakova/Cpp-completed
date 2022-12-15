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
#include <regex>
#include <iomanip>
#include <typeinfo>
#include "CustomerException.h"

//objednavky jsou multimapa, ktera je vektor s klicema
//[c1 => k1, c2 => k2, c3 => k3]
//pote jsme schopni jednoduse pristoupit k prvku mapy
//udela vektor, klice jsou cislovani zakazniku treba
//kdyz insertujeme, musime insertovat par

Store::Store() {
}

void Store::addCustomer(const int memberId, const float age,
                        const std::string name, const std::string address) {
    
    //zkraceny zapis konstruktoru
//    Customer customer {memberId, age, false, name, address};
//    m_customers.push_back(customer);
    

    if ( !std::regex_match(name, std::regex("^[A-Za-z]+$"))
        or memberId < 0
        or age < 0
        or name.empty()
        or address.empty()
        ) {
        throw std::invalid_argument("Argumenty jsou spatneho typu");
    }
    m_customers.push_back({memberId, age, false, name, address});
    
}

void Store::selectActiveCustomer(const int memberId) {
    // dodnes bychom ho delali pomoci for cyklu a najdem customera
    //dnes pomoci STL algoritmu
    
    //odkud, kam, lambda vyraz
    auto cust =
        std::find_if(m_customers.begin(), m_customers.end(), [memberId](const Customer &c)-> bool{
        // -> bool je volitelne, nemusi to tam byt
        //vraci jen iterator na zakaznika, ale ne toho samotneho zakaznika
        return c.memberId == memberId;
    });
    if(cust == m_customers.end()){
        throw std::out_of_range("Zakaznik nenalezen");
    }else if (cust == m_activeCustomer) {
        throw CustomerException("This customer is already active!", memberId);
    }else {
        m_activeCustomer = cust;
    }
}

void Store::addItemToBasket(const float price, const std::string description) {
    m_basket.push_back(Item{description, price});

}

void Store::emptyBasket() {
    m_basket.clear();
}

void Store::placeOrder() {
    // vytvori z itemu v kosiku novou order do orders
    //    std::multimap<Customer *, Order> m_orders;
    // basket je v Itemech!
    
    if (m_basket.empty()) {
            throw StoreException("Your basket is empty.");
        }
    
    Order order;
    
    // CAS - ziskani aktualniho casu
    order.time = std::chrono::system_clock::now();
    
    // STATUS - musi tu byt napsany nazev tridy ze ktere to je OrderStatus::
    order.status = OrderStatus::New;
    
    //* VECTORU - vektor musi mit stejnou velikost jako m_basket
    order.items.resize(m_basket.size());
    
    // ZKOPIROVANI - ZACATEK ODKUD | KONEC ODKUD | ZACATEK KAM
    std::copy(m_basket.begin(), m_basket.end(), order.items.begin());
    
    // PRIDANI ORDERU - &(*) = unwrapne iterator a vytvori ukazatel na Customera
    m_orders.insert(std::pair<Customer*, Order>(&(*m_activeCustomer), order));
    
    emptyBasket();
    setVipStatus();
    
}

void Store::sortCustomersByVipStatus() {
 
    //1. krok - seradit vektor podle abecedy
    std::sort(m_customers.begin(),m_customers.end(),
              //zadny focus nic se nemeni | 2 customeri | porovnaji se jejich jmena
              [](const Customer &customer1, const Customer &customer2) -> bool{
            return customer1.name > customer2.name;
    });
    
    //2. krok - seradit je v te abecede podle VIP membershipu
    std::stable_sort(m_customers.begin(), m_customers.end(),
                     [](const Customer &c1, const Customer &c2){
//        bud takto nebo:
//         if ( (c1.vipMember == false) and (c2.vipMember == true) ){
//        return false;
//        }
        return ((c1.vipMember and !c2.vipMember) || (c1.vipMember == c2.vipMember));
    });
}

void Store::printAllCustomers() const {
// KLASICKY:
//      for(auto customer: m_customers){
//        std::cout << "Name: " << customer.name;
//        std::cout << " Address: " << customer.address;
//        std::cout << " Age: " << customer.age << std::endl;
//    }
    
    for_each(m_customers.begin(), m_customers.end(),
                 [](const Customer &cus) -> void {
                     std::cout << "Jmeno: " << cus.name << "\tvek:" << cus.age
                               << "\tvip: " << cus.vipMember << std::endl;
                 });
}

void Store::printDatesOfNewOrders() {
    //kontrola nepresahnuti
    int check = 0;
    //projit celou multimapu
    for_each(m_orders.begin(), m_orders.end(),
             //zadne focusovani | hledame v parech multimapy |
             [&check](const std::pair<Customer *, Order> &pair) /*throw (std::out_of_range)*/ -> void {
            if(pair.second.status == OrderStatus::New ){
            
            //vytahne z vektoru m_orders, ze sloupce second atribut time
                std::time_t now = std::chrono::system_clock::to_time_t(pair.second.time - std::chrono::hours(24)); //odecti 24 hodin od nejakeho casu
                
                //vypise cas
                std::cout << "Date of order: " << std::ctime(&now);
        }
        //kontrola
        if(check == 1){
            throw std::out_of_range("No more dates awailable");
        }
        ++check;
    });
}


void Store::printBasketInfo() {
    //ci je to kosik, musime rozbalit zakaznika aby nebyl jen iterator
    std::cout << "Zakaznik: " << (*m_activeCustomer).name << std::endl;
    
    //musi to prohledavat iteratorem!
    for_each(m_basket.begin(), m_basket.end(),
             [](const Item &i) -> void{
                std::cout << "Description: " << i.description;
                std::cout << " Price: " << i.price << std::endl;
    });
}

void Store::setVipStatus() {
    //jestli ma zakaznik vice nez 3 objednavky
    //unwrapneme aktualniho customera, vytvorime na nej referenci &
    Customer* customer = &(*m_activeCustomer);
    
    //vsechno ordery pro customera
    auto range = m_orders.equal_range(customer);
    
    //spocitame kolik orderu to je
    long count = std::distance(range.first, range.second);
    
    
    //    NEBO KLASICKY:
    //    int count = 0;
    //    for (auto & m_order : m_orders) {
    //        if (m_order.first->memberId == m_activeCustomer->memberId) {
    //            count++;
    //        }
    //    }
    
    //    NEBO JESTE LIP:
    //    if( m_orders.count(&(*m_activeCustomer)) >= 3){
    //        setVipStatus();
    //    }
    
    if(count > 3){
        m_activeCustomer->vipMember = true;
    }
     
}

//----------------------------
//POMOCNE FUNKCE PRO TESTOVANI
//----------------------------

Customer* Store::getActiveCustomer() const{
    //tady musime posilat ukazatel (*) -> Customer* - musi tu byt hvezdicka jinak je to jen iterator
    return &(*m_activeCustomer);
}

std::vector<Customer> Store::getCustomers() const{
    return m_customers;
}
std::vector<Item> Store::getBasket() const{
    return m_basket;
}
std::multimap<Customer *, Order> Store::getOrders() const{
    return m_orders;
}




