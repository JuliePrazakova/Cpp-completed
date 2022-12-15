//
// Created by ivo on 24/10/22.
//

#ifndef COMPLETE_ICE_H
#define COMPLETE_ICE_H

#include <iostream>

struct Ice {
    float m_weight;
    float m_temperature;

    void printInfo() const {
        std::cout << "This is Ice with weight " << m_weight << " kg and temperature " << m_temperature << " deg C." << std::endl;
    }
};


#endif //COMPLETE_ICE_H
