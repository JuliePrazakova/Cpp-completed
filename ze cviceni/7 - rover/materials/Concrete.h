//
// Created by ivo on 24/10/22.
//

#ifndef COMPLETE_CONCRETE_H
#define COMPLETE_CONCRETE_H

#include <iostream>
#include "Soil.h"

struct Concrete {
    float m_weight;

    const float m_density = 0.2f;
    const float m_loss_factor = 0.3f;

    Concrete(Soil soil) {
        m_weight = soil.m_weight * m_density * (1 - m_loss_factor);
    }

    void printInfo() const {
        std::cout << "This is Concrete with weight " << m_weight << " kg." << std::endl;
    }
};


#endif //COMPLETE_CONCRETE_H
