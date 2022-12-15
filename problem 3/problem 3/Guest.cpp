//
//  Document.cpp
//  cpp
//
//  Created by Ivo Pisarovic on 15/01/2020.
//  Copyright © 2020 David. All rights reserved.
//

#include "Guest.hpp"
#include <regex>

// 6 bodu
/// Konstruktor navstevnika ski arealu.
/// Overte validitu vstupnich argumentu - 1b
/// Pokud cokoliv nesedi, vyhodte vhodnou vyjimku - 1b
/// - Parametr id musi byt vetsi rovno 0.
/// - Parametr name musi byt neprazdne.
/// - Parametr vek musi byt vetsi nez 0.
/// Dale podle veku rozhodnete, zda ma navstevnik slevu - 1b
/// Dale pomoci jednoho regularniho vyrazu zjistete, zda lekarska zprava obsahuje pozitivni nalez nemoci COVID-19 - 3b
/// Pozor, zprava muze obsahovat ruznou velikost pismen a vyjadreni teto informace.
/// Zajistete odchyceni nasledujicich formatu:
/// covid19, covid2019, covid 19, covid 2019 ... a to same s ruznou velikosti pismen

Guest::Guest(long id, std::string name, int age, std::string doctorsMessage){
    if(id < 0) {
        throw std::invalid_argument("Id cannot be smaller than 0.");
    }
    
    if (name == ""){
        throw std::invalid_argument("Name cannot be empty.");
    }
    if(age <= 0){
        throw std::invalid_argument("Age cannot be smaller or 0.");
    }else{
        if(age < 15){
            m_hasChildDiscount = true;
        }else{
            m_hasChildDiscount = false;
        }
    }

    //odchyt regularnim vyrazem covid
    std::regex reg(".*[cC][oO][vV][iI][dD]\\s?2?0?19.*");
    if (regex_match(doctorsMessage, reg)) {
        m_hasCovid = true;
    } else {
        m_hasCovid = false;
    }
    
    m_id = id;
    m_name = name;
}

long Guest::getId() const{
    return m_id;
}
std::string Guest::getName() const{
    return m_name;
}
bool Guest::getDiscount() const{
    return m_hasChildDiscount;
}
bool Guest::getCovid() const{
    return m_hasCovid;
}
