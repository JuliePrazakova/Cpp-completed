//
//  Ice.h
//  7 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#ifndef Ice_h
#define Ice_h


#include <iostream>

struct Ice {
    float m_weight;
    float m_temperature;

    void printInfo() const {
        std::cout << "This is Ice with weight " << m_weight << " kg and temperature " << m_temperature << " deg C." << std::endl;
    }
};


#endif /* Ice_h */
