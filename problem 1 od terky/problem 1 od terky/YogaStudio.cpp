#include "YogaStudio.hpp"

YogaStudio::YogaStudio(std::string name) {
    m_studioName = name;
    m_lessons = {};
}

void YogaStudio::addLesson(Lesson lesson) {
    m_lessons.push_back(lesson);
}

void YogaStudio::registerParticipant(long lessonId, Participant participant) {
    auto it = std::find_if(m_lessons.begin(), m_lessons.end(), [lessonId](const Lesson &less) -> bool {
        return less.getId() == lessonId;
    });

    if (it == m_lessons.end()){
        throw std::out_of_range("lekce neexistuje");
    } else {
        it->addParticipant(participant);
    }
}

void YogaStudio::printTimetable(std::string fileName) {
    std::ofstream out;
    out.open(fileName);

    if (out.is_open()){
        std::for_each(m_lessons.begin(), m_lessons.end(), [&out](const Lesson &less) -> void {
            out << "ID: " << less.getId() << "\n" << "name: " << less.getName() << "\n" << "content: " << less.getContent() << "\n" << "duration: " << less.getDurationInHours() << "h\n" << "number of participants: " << less.getNumOfParticipants() << "\n";
        });
        out.close();
    } else {
        std::cerr << "Soubor neotevren" << std::endl;
    }
}

std::vector<Lesson> YogaStudio::getEmptyLessons() const {
    std::vector<Lesson> emptyLessons;

    std::count_if(m_lessons.begin(), m_lessons.end(), [&emptyLessons](const Lesson &less) -> bool {
        if(less.getNumOfParticipants() == 0){
            emptyLessons.push_back(less);
            return true;
        } else {
            return false;
        }
    });
    return emptyLessons;
}

std::vector<Lesson> YogaStudio::getLessonsWithDurationInRange(long min, long max) const {
    if (max < min){
        throw std::invalid_argument("max je mensi jak min");
    }
    std::vector<Lesson> inRange;

    std::count_if(m_lessons.begin(), m_lessons.end(), [&inRange, min, max](const Lesson &less){
        if (less.getDuration() <= max and less.getDuration() >= min){
            inRange.push_back(less);
            return true;
        } else {
            return false;
        }
    });
    return inRange;
}

float YogaStudio::getRatioOfManAndWoman() const {
    int totalMale = 0, totalFemale = 0;
    std::for_each(m_lessons.begin(), m_lessons.end(), [&totalMale, &totalFemale](const Lesson &less) -> bool{
        std::vector<Participant> participants = less.getParticipants();
        int female = std::count_if(participants.begin(), participants.end(), [](const Participant &par) -> bool {
            return par.gender == Gender::female;
        });
        int male = std::count_if(participants.begin(), participants.end(), [](const Participant &par) -> bool {
            return par.gender == Gender::male;
        });
        totalFemale += female;
        totalMale += male;
    });

    return totalMale/totalFemale;
}

