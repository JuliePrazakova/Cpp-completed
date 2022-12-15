//
//  Document.cpp
//  cpp
//
//  Created by Ivo Pisarovic on 15/01/2020.
//  Copyright © 2020 David. All rights reserved.
//

#include "Lesson.hpp"
#include <regex>

/// 6 bodu
/// Overte validitu vsech argumentu:
/// Parametr id musi byt vetsi rovno nule.

/// Parametr content musi byt neprazdny.
/// Parametr duration musi byt vetsi jak nula.
/// Pokud cokoliv nesedi, vyhodte vhodnou vyjimku. = pro kazde zlast podm.
Lesson::Lesson(long id, std::string name, std::string content, long duration){
    if(id < 0) {
        throw std::invalid_argument("Id cannot be smaller than 0.");
    }
    
    if (content == ""){
        throw std::invalid_argument("Content cannot be empty.");
    }
    if(duration <= 0){
        throw std::invalid_argument("Duration cannot be smaller or 0.");
    }
    
    std::string tmpName = name;
//    std::regex reg("([[:alpha:]]+)([[:digit:]]+)?");
    std::regex reg("[^[:digit:]][a-zA-Z0-9]+");
    if (regex_match(tmpName, reg)) {
        m_name = tmpName;
    } else {
        throw std::invalid_argument("spatny format jmena");
    }
    
    m_id = id;
    m_name = name;
    m_content = content;
    m_duration = duration;
    std::vector<Participant>  m_participants;
}

long Lesson::getId() const{
    return  m_id;
}

void Lesson::addParticipants(Participant par){
    m_participants.push_back(par);
}
std::vector<Participant> Lesson::getParticipants() const{
    return m_participants;
}
long Lesson::getDuration() const{
    return m_duration/3600; // v hodinach
}
std::string Lesson::getName() const{
    return m_name;
}
std::string Lesson::getContent() const{
    return m_content;
}



