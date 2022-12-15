//
//  Ticket.hpp
//  cpp_exam
//
//  Created by Ivo Pisařovic on 08.01.2022.
//

#ifndef Ticket_hpp
#define Ticket_hpp

#include <stdio.h>
#include <string>
#include "TicketState.h"

/*
 6b
 */

/// struktura uchovavajici informace o jednom listku
class Ticket {
private:
    long m_id;
    double m_price;
    TicketState m_state; // ticket's state
    std::string m_date; // purhcase date in format yyyy-mm-dd, např. 2022-01-10 (pozor na leading zeros, napr. "01" je 1. mesic)
    
public:
    Ticket(long id, double price, TicketState state, std::string date);
    /// Print all info about this ticket to the end of the given text file.
    /// 4b
    void printToFile(const std::string fileName) const;
    
    /// Vratte true, pokud datum zacina predanym prefixem. Jinak false.
    /// 2b
    bool doesDateStartWith(const std::string prefix) const;
    
    std::string getLastLine(const std::string fileName) const;
    
    long getId();
};

#endif /* Ticket_hpp */
