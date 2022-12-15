//
//  Maze.hpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include <array>
#include "Worm.hpp"

class Maze {
private:
    Worm* worm;
    std::array<std::array<char, 5>, 5> plan; //mapa 5 * 5 policek
public:
    Maze();
    void print() const;
    bool checkDirection(int x, int y) const;
    void moveWorm(int x, int y);
};

#endif /* Maze_hpp */
