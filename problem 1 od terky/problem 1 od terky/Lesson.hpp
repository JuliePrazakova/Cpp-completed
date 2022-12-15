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
#include <regex>
#include "Participant.h"

/// 6 bodu
class Lesson {
private:
    long m_id;
    std::string m_name;
    std::string m_content;

    /// Duration of the lesson in seconds.
    long m_duration;

    std::vector<Participant> m_participants;
    
public:
    // 6 bodu
    /// Overte validitu vsech argumentu:
    /// Parametr id musi byt vetsi rovno nule.
    /// Parametr name overte pomoci regularu: musi byt neprazdny, musi obsahovat pouze pismena a cislice, nesmi zacinat cislici.
    /// Parametr content musi byt neprazdny.
    /// Parametr duration musi byt vetsi jak nula.
    /// Pokud cokoliv nesedi, vyhodte vhodnou vyjimku.
    Lesson(long id, std::string name, std::string content, long duration);

    long getId() const;
    std::string getName() const;
    std::string getContent() const;
    long getDurationInHours() const;
    long getDuration() const;
    int getNumOfParticipants() const;
    std::vector<Participant> getParticipants() const;
    void addParticipant(Participant part);
    
};

#endif /* Document_hpp */
