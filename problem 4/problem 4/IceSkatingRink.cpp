//
//  IceSkatingRink.cpp
//  cpp_exam
//
//  Created by Ivo Pisařovic on 08.01.2022.
//

#include <stdio.h>
#include "IceSkatingRink.hpp"


/// Konstruktor ulozi kapacitu kluziste do atributu capacity.
/// 1b
//IceSkatingRink::IceSkatingRink(const int capacity){
//    this->capacity = capacity;
//}

/// Zakoupi listek - vytvori instanci a prida do atributu tickets.
/// Nastavi jeho stav na zakoupeny.
/// Cenu nastavi podle toho, zda je to dospely (50) nebo dite (20).
/// Dnesni datum je predany jako string parametr.
/// ID nastavi tak, aby bylo o 1 vyssi nez u vsech predchozich listku.
/// Po zakoupeni listku vypiste info do souboru pomoci metody v Ticket.
/// Vrati novy listek.
/// 5b
Ticket* IceSkatingRink::buyTicket(const bool isChild, const std::string date){
   //
    int price;
    if(isChild){
        price = 20;
    }else{
        price = 50;
    }
    long id = std::prev(tickets.end())->second->getId() + 1;
    
    Ticket *t = new Ticket(id, price, TicketState::Bought, date);
    t->printToFile("ticket.txt");
    return t;
}

/// Listek je pouzit ke vstupu na kluziste.
/// Zmeni stav listku s danym ID (pouzijte klic v std::map, nepouzivejte getTicketById).
/// V pripade uspechu vrati true.
/// Pokud je na kluzisti vice jak capacity lidi, nic se nestane a vrati se false.
/// 3b
bool IceSkatingRink::enterRink(const long id){
    
}

/// Listek je pouzit k odchodu z kluziste.
/// Zmeni stav listku s danym ID (pouzijte getTicketById, NEpouzijte klic v std::map)..
/// Pokud listek jeste nebyl pouzit ke vstupu (entered), vyhodte vyjimku.
/// 4b
void IceSkatingRink::exitRink(const long id){
    
}

/// Vrati vsechny listky, ktere jsou detske a ktere jsou aktualne na kluzisti (entered).
/// Pouzijte STL algoritmus. NEpouzivejte klic v std::map
/// 4b
//std::vector<Ticket> IceSkatingRink::getAllChildEnteredTickets() const{
//    std::vector<Ticket> tiskets;
//
//    return tickets;
//}

/// Vrati ticket podle ID.
/// Pouzijte STL algoritmus.
/// Pokud neexistuje zadny listek s danym ID, vyhodte vhodnou vyjimku.
/// 4b
Ticket IceSkatingRink::getTicketById(const long id) const{
    Ticket* t;
    return *t;
}

/// Vratte vsechny listky, ktere byly zakoupeny v predany rok, mesic a den.
/// (Den) nebo (mesic a den) jsou volitelne - mohou byt "0" a pak se nepouziji pro filtrovani.
/// Pokud jsou vsechny tri parametry "0", vyhodte vhodnou vyjimku.
/// Pouzijte STL algoritmus a metodu Ticket::doesDateStartWith.
/// 6b
std::vector<Ticket> IceSkatingRink::getAllTicketsFrom(const int year, const int month, const int day) const{
    std::vector<Ticket> tickets;
    return tickets;
}
