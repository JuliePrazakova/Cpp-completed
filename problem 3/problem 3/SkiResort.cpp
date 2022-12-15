#include "SkiResort.hpp"

SkiResort::SkiResort() {
    m_guests = {};
}

/// 1 bod
/// Novy navstevnik prijel do ski arealu. Zaregistrujte ho.
void SkiResort::addGuest(Guest guest){
    m_guests.push_back(guest);
}

/// 4 body
/// Vytisknete zakaznikovi jizdenku.
/// Jizdenku vytisknete do textoveho souboru.
/// Format:
/// Jmeno * (hvezdicku vypiste jen tehdy, pokud ma navstevnik covid)
/// A/C (A pokud je to dospely, C pokud ma detskou slevu)
/// Cena XX Kc (kde XX je 750Kc pro dospeleho a 350 Kc pro dite)
/// Dbejte na spravne otevreni a uzavreni souboru.
void SkiResort::printTicket(Guest guest){
    std::ofstream out("ticket");
    
    if(out.is_open()){
        std::string covid = (guest.getCovid()) ? " *" : ""; //inlinove if() at setrime misto
        std::string discount = (guest.getDiscount()) ? " C" : " A";
        std::string price = (guest.getDiscount()) ? " 350Kc" : " 750Kc";
        
        // zapis do souboru:
        out << "Jmeno: " << guest.getName() << covid << "\n" << discount << "\n"<< "Cena" <<price << "\n";
        
        // zavrit vystup
        out.close();
    }else{
        throw std::invalid_argument("Soubor nelze otevrit");
    }
}

// 4 body
/// Vratte kolik procent navstevniku ma COVID.
float SkiResort::getRatioOfCovidPositiveGuests() const{
    float totalPositive = 0, totalNegative = 0;

    std::for_each(m_guests.begin(), m_guests.end(), [&totalPositive, &totalNegative](const Guest &guest) -> bool {
        if(guest.getCovid()){
            totalPositive++;
        }else{
            totalNegative++;
        }
        return false;
    });
    float total = (totalPositive/(totalPositive+totalNegative))*100;
    return total;
}

// 5 body
/// Vrati vsechny navstevniky serazene podle abecedy od konce.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Guest> SkiResort::getSortedGuests() const{
    std::vector<Guest> sorted_guests = m_guests;
    std::sort(sorted_guests.begin(), sorted_guests.end(), [](const Guest &guest1, const Guest &guest2) -> bool {
       return guest1.getName().at(0) > guest2.getName().at(0);
    });
    return sorted_guests;
}

// 6 bodu
/// Spočítejte počet dětí.
/// Pouzijte STL algoritmus a lambda vyraz.
long SkiResort::getCountOfChildren() const{
    long numOfChildren = std::count_if(m_guests.begin(), m_guests.end(), [](const Guest &guest) -> bool {
        return guest.getDiscount();
    });
    return numOfChildren;
}

/// 8 bodu
/// Vratte vsechny navstevniky, jejich jmeno zacina pismenem predanym jako parametr.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Guest> SkiResort::getGuestsStartingWith(char firstLetter) const{
    std::vector<Guest> guests;
   std::for_each(m_guests.begin(), m_guests.end(), [firstLetter, &guests](const Guest &guest){
       if(guest.getName()[0] == firstLetter){
           guests.push_back(guest); 
       }
    });
    return guests;
}
