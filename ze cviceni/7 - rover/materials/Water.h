//
// Created by ivo on 24/10/22.
//

#ifndef COMPLETE_WATER_H
#define COMPLETE_WATER_H

#include <iostream>
#include "Ice.h"

struct Water {
    float m_volume;

    const float m_density = 1.0f;
    const float m_loss_factor = 0.1f;

    Water(Ice ice) {
        m_volume = ice.m_weight * m_density * (1 - m_loss_factor);
    }

    void printInfo() const {
        std::cout << "This is Water with volume " << m_volume << " litres." << std::endl;
    }
};


#endif //COMPLETE_WATER_H
