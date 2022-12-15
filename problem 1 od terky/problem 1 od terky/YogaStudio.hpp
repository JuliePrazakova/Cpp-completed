#ifndef cpp_priklad1_h
#define cpp_priklad1_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "Lesson.hpp"

// 28 bodu
class YogaStudio {
private:
    std::string m_studioName;
    /// Struktura obsahujici vsechny lekce.
    std::vector<Lesson> m_lessons;

public:
    YogaStudio(std::string name);

    /// 1 bod
    /// Pridejte predanou lekci do vektoru lekci m_lessons.
    void addLesson(Lesson lesson);

    /// 3 bod
    /// Najdete lekci s danym id.
    /// Pridejte predaneho ucastnika na tuto lekci.
    /// Pokud lekce s danym ide neexistuje, vyhodte vhodnou vyjimku.
    void registerParticipant(long lessonId, Participant participant);

    // 7 body
    /// Vypiste do textoveho souboru rozvrh lekci jako tabulku, kde lekce jsou ve sloupcich.
    /// Delku trvani vypiste v hodinach.
    /// Priklad:
    ///
    /// ID                     | 1                               | 2
    /// name                   | Vinyasa flow                    | Stretching hamstrings
    /// content                | The basics of vinyasa are ....  | This lesson is focused on ...
    /// duration [h]           | 1.5 hours                       | 0.5 hours
    /// number of participants | 12                              | 4
    ///
    /// Nazev souboru je predany jako parametr.
    void printTimetable(std::string fileName);
    
    // 5 body
    /// Vrati vsechny lekce s nula ucastniky.
    /// Pouzije STL algoritmus a lambda vyraz.
    std::vector<Lesson> getEmptyLessons() const;
    
    // 7 bodu
    /// Vratte seznam lekci, jejichz roszsah je mezi min a max, vcetne.
    /// Pokud je max mensi jak min, vyhodte vhodnou vyjimku.
    /// Pouzijte STL algoritmus a lambda vyraz.
    std::vector<Lesson> getLessonsWithDurationInRange(long min, long max) const;
    
    // 5 body
    /// Vratte podil muzu a zen na vsech lekcich.
    /// Celkovy pocet muzu deleno celkovy pocet zen.
    float getRatioOfManAndWoman() const;
    
};

#endif
