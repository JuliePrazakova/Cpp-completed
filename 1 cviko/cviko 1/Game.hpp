//
//  Game.hpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#ifndef Game_hpp
#define Game_hpp
#include "Maze.hpp"
#include <stdio.h>

class Game{
private:
    Maze* maze;
    void printIntroduction();
    void printOptions();
    char waitForInput();
    void printEnd();
    void processInput(char input);
    void tryMovingWorm(int x, int y);
    
public:
    Game();
    void start();
    
    
};

#endif /* Game_hpp */
