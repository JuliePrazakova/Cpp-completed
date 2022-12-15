//
//  Worm.cpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include "Worm.hpp"

Worm::Worm(int x, int y){
    m_x = x;
    m_y = y;
}
int Worm::getX(){
    return m_x;
}
int Worm::getY(){
    return m_y;
}
void Worm::moveTo(int x, int y){
    m_x = x;
    m_y = y;
}
