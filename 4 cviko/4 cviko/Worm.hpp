//
//  Worm.hpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#ifndef Worm_hpp
#define Worm_hpp

#include <stdio.h>

class Worm{
private:
    int m_x;
    int m_y;
    
public:
    static const char symbol = '@'; //nebude se menit
    Worm(int x, int y);
    int getX();
    int getY();
    void moveTo(int x, int y);
};

#endif /* Worm_hpp */
