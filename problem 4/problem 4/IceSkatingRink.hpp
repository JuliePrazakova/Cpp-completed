#ifndef PRIKLAD1_H
#define PRIKLAD1_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Ticket.hpp"

/*
 27 b
*/

class IceSkatingRink {
    
private:
    /// kolekce vsech listku
    /// klicem je ID listk
    /// hodnotou je listek
    std::map<long, Ticket*> tickets;
    
    // kolik lidi muze byt uvnitr (stav = Entered)
    const int capacity;
    
public:
    /// Konstruktor ulozi kapacitu kluziste do atributu capacity.
    /// 1b
    IceSkatingRink(const int capacity);
    
    /// Zakoupi listek - vytvori instanci a prida do atributu tickets.
    /// Nastavi jeho stav na zakoupeny.
    /// Cenu nastavi podle toho, zda je to dospely (50) nebo dite (20).
    /// Dnesni datum je predany jako string parametr.
    /// ID nastavi tak, aby bylo o 1 vyssi nez u vsech predchozich listku.
    /// Po zakoupeni listku vypiste info do souboru pomoci metody v Ticket.
    /// Vrati novy listek.
    /// 5b
    Ticket* buyTicket(const bool isChild, const std::string date);
    
    /// Listek je pouzit ke vstupu na kluziste.
    /// Zmeni stav listku s danym ID (pouzijte klic v std::map, nepouzivejte getTicketById).
    /// V pripade uspechu vrati true.
    /// Pokud je na kluzisti vice jak capacity lidi, nic se nestane a vrati se false.
    /// 3b
    bool enterRink(const long id);
    
    /// Listek je pouzit k odchodu z kluziste.
    /// Zmeni stav listku s danym ID (pouzijte getTicketById, NEpouzijte klic v std::map)..
    /// Pokud listek jeste nebyl pouzit ke vstupu (entered), vyhodte vyjimku.
    /// 4b
    void exitRink(const long id);
    
    /// Vrati vsechny listky, ktere jsou detske a ktere jsou aktualne na kluzisti (entered).
    /// Pouzijte STL algoritmus. NEpouzivejte klic v std::map
    /// 4b
    std::vector<Ticket*> getAllChildEnteredTickets() const;
    
    /// Vrati ticket podle ID.
    /// Pouzijte STL algoritmus.
    /// Pokud neexistuje zadny listek s danym ID, vyhodte vhodnou vyjimku.
    /// 4b
    Ticket* getTicketById(const long id) const;
    
    /// Vratte vsechny listky, ktere byly zakoupeny v predany rok, mesic a den.
    /// (Den) nebo (mesic a den) jsou volitelne - mohou byt "0" a pak se nepouziji pro filtrovani.
    /// Pokud jsou vsechny tri parametry "0", vyhodte vhodnou vyjimku.
    /// Pouzijte STL algoritmus a metodu Ticket::doesDateStartWith.
    /// 6b
    std::vector<Ticket*> getAllTicketsFrom(const int year, const int month, const int day) const;
    
};

#endif // PRIKLAD1_H_INCLUDED
