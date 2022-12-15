//
// Created by Ivo Pisařovic on 04/01/2021.
//

#ifndef ZKOUSKA_ZS2021_1T_PARTICIPANT_H
#define ZKOUSKA_ZS2021_1T_PARTICIPANT_H

#include <string>
#include "Gender.h"

struct Participant {
    std::string name;
    int age;
    Gender gender;
};

#endif //ZKOUSKA_ZS2021_1T_PARTICIPANT_H
