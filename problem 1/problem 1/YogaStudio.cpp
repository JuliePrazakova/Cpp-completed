#include "YogaStudio.hpp"

//YogaStudio::YogaStudio(std::string name) {
//    m_studioName = name;
//    m_lessons = {};
//}

/// Pridejte predanou lekci do vektoru lekci m_lessons.
void YogaStudio::addLesson(Lesson lesson){
    m_lessons.push_back(lesson);
}

/// 3 bod
// Najdete lekci s danym id.
// Pridejte predaneho ucastnika na tuto lekci.
// Pokud lekce s danym ide neexistuje, vyhodte vhodnou vyjimku.
void YogaStudio::registerParticipant(long lessonId, Participant participant){
    long count = m_lessons.size() - 1;
    
    for(auto l = m_lessons.begin(); l != m_lessons.end(); l++){
            if(l->getId() == lessonId){
                l->addParticipants(participant);
            }
            if(count == m_lessons.size()){
                throw std::out_of_range("Customer not found");
            }
            count -=1;
        };
    
//    auto it = std::find_if(m_lessons.begin(), m_lessons.end(), [lessonId](const Lesson &less) -> bool {
//        return less.getId() == lessonId;
//    });
//
//    if (it == m_lessons.end()){
//        throw std::out_of_range("lekce neexistuje");
//    } else {
//        it->addParticipant(participant);
//    }
}

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
void YogaStudio::printTimetable(std::string fileName){
    std::ofstream file; //instance open streamu
        file.open(fileName);
        
        if(file.is_open()){
            
            file << "ID           \n ";
            for(auto l = m_lessons.begin(); l != m_lessons.end(); l++){
                file << "|" << l->getId() << "\n";
            }
            file << std::endl;
            
            file << "name         \n " ;
            for(auto l = m_lessons.begin(); l != m_lessons.end(); l++){
                file <<"|" << l->getName()<< "\n";
            }
            file << std::endl;
    
            file << "content      \t " ;
            for(auto l = m_lessons.begin(); l != m_lessons.end(); l++){
                file <<"|" << l->getContent()<< "\t";
            }
            file << std::endl;

            file << "duration [h]  \t" ;
            for(auto l = m_lessons.begin(); l != m_lessons.end(); l++){
                float hours =  (l->getDuration())/3600;
                file <<"|" << hours << "\t";
            }
            file << std::endl;
            
            file << "participants \t " ;
            for(auto l = m_lessons.begin(); l != m_lessons.end(); l++){
                auto number = (l->getParticipants()).size();
                file <<"|" << number << "\t";
            }
            file << std::endl;
            
            file.close();
        }else { //odchyceni vyjimky a vypsani chybove hlasky!!
            std::cerr << "Cannot open file." <<std::endl;
        }
}

// 5 body
/// Vrati vsechny lekce s nula ucastniky.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Lesson> YogaStudio::getEmptyLessons() const{
    std::vector<Lesson> empty_lessons;
    
    for_each(m_lessons.begin(), m_lessons.end(), [this, &empty_lessons](const Lesson &l){
        if((l.getParticipants()).empty()){
            empty_lessons.push_back(l);
            //return true ???
        }
    });
    return empty_lessons;
}

// 7 bodu
/// Vratte seznam lekci, jejichz roszsah je mezi min a max, vcetne.
/// Pokud je max mensi jak min, vyhodte vhodnou vyjimku.
/// Pouzijte STL algoritmus a lambda vyraz.
std::vector<Lesson> YogaStudio::getLessonsWithDurationInRange(long min, long max) const{
    std::vector<Lesson> chosen_lessons;
    
    if(max < min){
        throw std::invalid_argument("Max duration cannot be smaller than min duration");
    }
    
    for_each(m_lessons.begin(), m_lessons.end(), [this, &chosen_lessons, min, max](const Lesson &l){
            if( min > l.getDuration() > max){
            chosen_lessons.push_back(l);
        }
    });
    return chosen_lessons;
}

// 5 body HOTOVO
/// Vratte podil muzu a zen na vsech lekcich.
/// Celkovy pocet muzu deleno celkovy pocet zen.
float YogaStudio::getRatioOfManAndWoman() const{
    float female = 0;
    float male = 0;
    float other = 0;
    
    for_each(m_lessons.begin(), m_lessons.end(), [this, &female, &male, &other](const Lesson &l){
        std::vector<Participant> p = l.getParticipants(); //vytahneme ucastniky z l
        
        for_each(p.begin(), p.end(), [&female, &male, &other](const Participant &par){
            if(par.gender == Gender::female){
                female +=1;
            }else if(par.gender == Gender::male){
                male +=1;
            }else {
                other +=1;
            }
        });
    });
        
    return male / female;
}
