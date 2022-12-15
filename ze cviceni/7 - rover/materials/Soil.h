//
// Created by ivo on 24/10/22.
//

#ifndef COMPLETE_SOIL_H
#define COMPLETE_SOIL_H

#include <iostream>
#include <string>

struct Soil {
    float m_weight;
    std::string m_composition;

    void printInfo() const {
        std::cout << "This is Soil with weight " << m_weight << " kg and composition made of " << m_composition << "." << std::endl;
    }
};


#endif //COMPLETE_SOIL_H
