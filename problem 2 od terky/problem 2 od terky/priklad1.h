#ifndef PRIKLAD1_H
#define PRIKLAD1_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>

/*
 25 b
*/

/// vyctovy typ uchovavajici stav volebniho listku
enum class State {Accepted, Invalid, Damaged, Faked};
/// volena osoba
enum class Candidate {DonaldTrump, JoeBiden};

/// struktura uchovavajici popis jednoho volebniho listku
struct Ballot{
    State state;        // stav listku
    Candidate person;   // volena osoba
    std::string date;   // datum podani listku ve formatu yyyymmddhhmm
};

/// Trida reprezentujici evidenci volebnich listku.
/// Pri implementaci metod pouzivejte v maximalni mozne mire algoritmy STL a lambda vyrazu!!!
class BallotList{
private:
    /// vektor vsech volebnich listku, klicem je id toho, kdo listek zapocital (napr. CNT01), hodnotou je samotny listek
    std::map<std::string, Ballot> m_orders;
public:
    /// Konstruktor, ktery zavola nacteni dat ze souboru a naplneni vektoru zaznamu
    /// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska
    /// na chybovy vystup - 2b
    BallotList();
    /// metoda nacitajici vsechny zaznamy ze souboru - 5b
    /// pozor: jmeno ma vice slov
    /// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
    void loadFile(const std::string fileName) throw (std::invalid_argument);
    /// metoda vlozi zaznam, provede transformaci pomoci labda vyrazu
    /// ze stringu na dany typ vyctu - 6b
    void insertBallot(const std::string state, const std::string person,
                      const std::string date, const std::string counter);
    /// vraci pocty hlasu daneho typu pro jednotlive kandidaty. Tj. vyberu napr. ze chci neplatne listky a vrati se map
    /// se dvema zaznamy: neplatne pro Trumpa a neplatne pro Bidena - 6b
    std::map<Candidate, long> getBallotsCount(const State state);
    /// metoda vraci listky daneho typu: platne, neplatne...
    /// pokud zaznam neni zadny zaznam nalezen, je vyhozena vyjimka - 6b
    std::vector<Ballot> getBallots(const State state) throw (std::invalid_argument);
};

#endif // PRIKLAD1_H_INCLUDED
