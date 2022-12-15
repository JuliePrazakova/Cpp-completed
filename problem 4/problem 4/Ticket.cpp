//
//  Ticket.cpp
//  cpp_exam
//
//  Created by Ivo Pisařovic on 08.01.2022.
//

#include "Ticket.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Ticket::Ticket(long id, double price, TicketState state, std::string date){
    m_id = id;
    m_price = price;
    m_state = state;
    m_date = date;
}


/// Print all info about this ticket to the end of the given text file.
/// 4b
void Ticket::printToFile(const std::string fileName) const{
    //std::ofstream out(fileName); normalne
    
    std::ofstream out;
    out.open(fileName, std::ios::app); //melo by pridavat na konec soubrou .txt
    
    if(out.is_open()){
        std::string state;
        if(m_state == TicketState::Bought){
            state = "Brought";
        }
        if(m_state == TicketState::Entered){
            state = "Entered";
        }
        if(m_state == TicketState::Exited){
            state = "Exited";
        }

        out << "ID: "<< m_id << " Price: " << m_price << " State: " << state <<" Date: " << m_date << std::endl;
        
        out.close();
    }else{
        throw std::invalid_argument("Soubor nelze otevrit");
    }
}

/// Vratte true, pokud datum zacina predanym prefixem. Jinak false.
/// 2b
bool Ticket::doesDateStartWith(const std::string prefix) const{
    long position = m_date.find("-"); // prvni oddelovac
    
    std::string dateAmonth = m_date.substr(position + 1, m_date.size() - position - 1); // zbavime se roku
    
    long position2 = dateAmonth.find("-"); // druhy oddelovac
    
    std::string date = dateAmonth.substr(position2 + 1, dateAmonth.size() - position2 - 1); // ziskame jen datum
    
    return date == prefix;
}

std::string Ticket::getLastLine(const std::string fileName) const{
    std::ifstream out(fileName);

    if(out.is_open()){
        out.seekg(-1,std::ios_base::end);                // go to one spot before the EOF

        bool keepLooping = true;
        while(keepLooping) {
            char ch;
            out.get(ch);                            // Get current byte's data
            if((int)out.tellg() <= 1) {             // If the data wa at or before the 0th byte
                out.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                out.seekg(-2,std::ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        std::string lastLine;
        getline(out,lastLine);                      // Read the current line
        std::cout << "Result: " << lastLine << '\n';     // Display it
        
        
        out.close();
        return lastLine;
    }else{
        throw std::invalid_argument("Soubor nelze otevrit");
    }
}

long Ticket::getId(){
    return m_id;
}

