#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H


#include <array>
#include "Tesla.h"

class Map {
private:
    Tesla* tesla;
    std::array<std::array<char, 5>, 5> plan;
//    _____
//    _____
//    _____
//    _____
//    _____
    
    bool isSupercharger(int x, int y) const;

public:
    Map();
    void print() const;
    void printTeslaInfo() const;
    bool checkDirection(int x, int y) const;
    void moveTesla(int x, int y);
    char getField(int x, int y) const;
    Tesla* getTesla() const;
};


#endif //UNTITLED_MAP_H
