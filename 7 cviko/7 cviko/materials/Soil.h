//
//  Soil.h
//  7 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#ifndef Soil_h
#define Soil_h
#include <iostream>

#include <string>

struct Soil {
    float m_weight;
    std::string m_composition;

    // tady si na random udelam metody protoze naraz neni nutne nikde delat tridy a dam to vsechno do structu
    void printInfo() const {
        std::cout << "This is Soil with weight " << m_weight << " kg and composition made of " << m_composition << "." << std::endl;
    }
};
#endif /* Soil_h */
