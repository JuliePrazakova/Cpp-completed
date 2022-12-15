//
//  Tesla.cpp
//  cviko 3
//
//  Created by Julie Pražáková on 12.12.2022.
//

#include "Tesla.hpp"

Tesla::Tesla(int x, int y){
    m_x = x;
    m_y = y;
    m_batery = 100;
}
int Tesla::getX(){
    return m_x;
}
int Tesla::getY(){
    return m_y;
}
int Tesla::getBatery(){
    return m_batery;
}
void Tesla::moveTo(int x, int y){
    m_x = x;
    m_y = y;
    m_batery -= 1;
}
void Tesla::addBatery(){
    if(m_batery <= 90){ // pokud nehrozi preteceni
        m_batery += 10;
    }else {
        m_batery = 100; // aby to nepreteklo pres 100
    }
}
