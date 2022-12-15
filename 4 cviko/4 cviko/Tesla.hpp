//
//  Tesla.hpp
//  cviko 3
//
//  Created by Julie Pražáková on 12.12.2022.
//

#ifndef Tesla_hpp
#define Tesla_hpp

#include <stdio.h>

class Tesla{
private:
    int m_x;
    int m_y;
    int m_batery;
    
public:
    static const char symbol = 'T'; //nebude se menit
    Tesla(int x, int y);
    int getX();
    int getY();
    int getBatery();
    void moveTo(int x, int y);
    void addBatery();
};

#endif /* Tesla_hpp */
