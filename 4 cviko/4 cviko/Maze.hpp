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
#include "Tesla.hpp"

class Maze {
private:
    Tesla* tesla;
    std::array<std::array<char, 5>, 5> plan; //mapa 5 * 5 policek
public:
    Maze();
    void print() const;
    bool checkDirection(int x, int y) const;
    void moveTesla(int x, int y);
    bool isSupercharger(int x, int y);
    void printBatery();
    
    // pomocne funkce pro testovani
    char getField(int x, int y) const;      // zkontrolujeme hodnotu tohoto pole
    Tesla* getTesla() const;                // pro kontrolu souradnic tesly
};

#endif /* Maze_hpp */
