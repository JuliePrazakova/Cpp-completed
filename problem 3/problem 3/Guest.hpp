//
//  Document.hpp
//  cpp
//
//  Created by Ivo Pisarovic on 15/01/2020.
//  Copyright © 2020 David. All rights reserved.
//

#ifndef Document_hpp
#define Document_hpp

#include <string>
#include <vector>

/// 6 bodu
class Guest {
private:
    long m_id;
    std::string m_name;
    bool m_hasChildDiscount;
    bool m_hasCovid;
    
public:
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
    Guest(long id, std::string name, int age, std::string doctorsMessage);
    long getId() const;
    std::string getName() const;
    bool getDiscount() const;
    bool getCovid() const;
};

#endif /* Document_hpp */
