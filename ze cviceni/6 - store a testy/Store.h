//
//  Store.h
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 11/6/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef __CPP_cviceni6_obchod__Store__
#define __CPP_cviceni6_obchod__Store__

#include <iostream>
#include <vector>
#include <map>
#include "Customer.h"
#include "Order.h"
#include <algorithm>

/**
 Engine obchodu realizujici objenavky a dalsi operace
 */
class Store {

private:
    std::vector<Customer> m_customers;        ///< seznam zakazniku obchodu
    std::multimap<Customer *, Order> m_orders;           ///< seznam objednavek

    std::vector<Customer>::iterator m_activeCustomer = m_customers.begin();   ///< zakaznik prave pracujici s obchodem
    std::vector<Item> m_basket;           ///< Nakupni kosik;
public:
    /// Konstruktor, pouze inicializuje atributy
    Store();

    /// Prida do vectoru zakaznika
    /// Pokud je nektery udaj neplatny (prazdny), vyhodte vyjimku std::invalid_argument a odchytte ji pri testovani teto metody
    void addCustomer(const int memberId, const float age,
                     const std::string name, const std::string address);

    /* -----------------------------------------------------------------*/
    // Nasledujici metody by mely byt v samostatne tride - Nakupni kosik,
    // ale abychom cviceni nekomplikovali, jsou zde
    /* -----------------------------------------------------------------*/
    /// Zvoli zakaznika, ktery prave se systemem pracuje
    /// Pokud zadny zakaznik s danym ID neexistuje, vyhodte vyjimku std::out_of_range a odchytte ji pri testovani teto metody
    /// Pokud jiz zakaznik aktivni je, vyhodte vyjimku CustomerException a odchytte ji pri testovani teto metody
    void selectActiveCustomer(const int memberId);

    /// Prida zbozi do kosiku
    void addItemToBasket(const float price, const std::string description);

    /// Vysype kosik
    void emptyBasket();

    /// Vypise informace o zbozi v kosiku
    void printBasketInfo();

    /// Vytvori objenavku ze zbozi v kosiku
    /// Pokud je kosik prazdny, vyhodte StoreException a odchytte ji pri testovani teto metody
    void placeOrder();
    /* -----------------------------------------------------------------*/

    /// Setrid zakazniky podle VIP statusu a nasledne podle abecedy
    /// Tj. nejdrive budou abecedne serazeni VIP a pak abecedne serazeny zbytek
    void sortCustomersByVipStatus();

    /// Vypise vsechny zakazniky
    void printAllCustomers() const;

    /// Vypise datumy objednani vsech dorucovanych objednavek
    void printDatesOfNewOrders();

    // helper methods added to support unit tests
    std::vector<Customer> getCustomers() const;
    Customer* getActiveCustomer() const;
    std::vector<Item> getBasket() const;
    std::multimap<Customer *, Order> getOrders() const;

private:
    /// Tato metoda je volana automaticky pri zadani kazde objednavky
    /// Pokud pocet objednavek presahne 3, ma zakaznik VIP status.
    void setVipStatus();
};

#endif /* defined(__CPP_cviceni6_obchod__Store__) */
