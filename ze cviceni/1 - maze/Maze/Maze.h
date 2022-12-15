//
// Created by Ivo Pisařovic on 24/09/2020.
//

#ifndef UNTITLED_MAZE_H
#define UNTITLED_MAZE_H


#include <array>
#include "Worm.h"

class Maze {
private:
    Worm* worm;
    std::array<std::array<char, 5>, 5> plan;
//    _____
//    _____
//    _____
//    _____
//    _____

public:
    Maze();
    void print() const;
    bool checkDirection(int x, int y) const;
    void moveWorm(int x, int y);

};


#endif //UNTITLED_MAZE_H
