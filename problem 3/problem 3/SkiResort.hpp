#ifndef cpp_priklad1_h
#define cpp_priklad1_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "Guest.hpp"

// 28 bodu
class SkiResort {
private:
    /// Struktura obsahujici vsechny lekce.
    std::vector<Guest> m_guests;

public:
    SkiResort();
    /// 1 bod
    /// Novy navstevnik prijel do ski arealu. Zaregistrujte ho.
    void addGuest(Guest guest);

    /// 4 body
    /// Vytisknete zakaznikovi jizdenku.
    /// Jizdenku vytisknete do textoveho souboru.
    /// Format:
    /// Jmeno * (hvezdicku vypiste jen tehdy, pokud ma navstevnik covid)
    /// A/C (A pokud je to dospely, C pokud ma detskou slevu)
    /// Cena XX Kc (kde XX je 750Kc pro dospeleho a 350 Kc pro dite)
    /// Dbejte na spravne otevreni a uzavreni souboru.
    void printTicket(Guest guest);

    // 4 body
    /// Vratte kolik procent navstevniku ma COVID.
    float getRatioOfCovidPositiveGuests() const;

    // 5 body
    /// Vrati vsechny navstevniky serazene podle abecedy od konce.
    /// Pouzije STL algoritmus a lambda vyraz.
    std::vector<Guest> getSortedGuests() const;
    
    // 6 bodu
    /// Spočítejte počet dětí.
    /// Pouzijte STL algoritmus a lambda vyraz.
    long getCountOfChildren() const;

    /// 8 bodu
    /// Vratte vsechny navstevniky, jejich jmeno zacina pismenem predanym jako parametr.
    /// Pouzije STL algoritmus a lambda vyraz.
    std::vector<Guest> getGuestsStartingWith(char firstLetter) const;

};

#endif
