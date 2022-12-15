//
//  Document.cpp
//  cpp
//
//  Created by Ivo Pisarovic on 15/01/2020.
//  Copyright © 2020 David. All rights reserved.
//

#include "Lesson.hpp"

Lesson::Lesson(long id, std::string name, std::string content, long duration){

    long tmpId = id;
    if (id < 0){
        throw std::out_of_range("Id je mensi jak O, Id musi byt vetsi rovno nule");
        tmpId = 0;
    }
    m_id = tmpId;

    std::string tmpName = name;
//    std::regex reg("([[:alpha:]]+)([[:digit:]]+)?");
    std::regex reg("[^[:digit:]][a-zA-Z0-9]+");
    if (regex_match(tmpName, reg)) {
        m_name = tmpName;
    } else {
        throw std::invalid_argument("spatny format jmena");
    }

    if (content != ""){
        m_content = content;
    } else {
        throw std::invalid_argument("prazdny content");
    }

    long tmpDuration = duration;
    if (tmpDuration <= 0) {
        throw std::out_of_range("trvani je prilis kratne, musi byt nejmene 0");
        tmpDuration = 1;
    }
    m_duration = tmpDuration;
}

long Lesson::getId() const {
    return m_id;
}

std::string Lesson::getName() const {
    return m_name;
}

std::string Lesson::getContent() const {
    return m_content;
}

long Lesson::getDurationInHours() const {
    return m_duration/3600;
}

long Lesson::getDuration() const {
    return m_duration;
}

int Lesson::getNumOfParticipants() const {
    return m_participants.size();
}

std::vector<Participant> Lesson::getParticipants() const {
    return m_participants;
}

void Lesson::addParticipant(Participant part) {
    m_participants.push_back(part);
}