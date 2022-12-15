//
//  main.cpp
//  cviko 2
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    Game* game = new Game();
    game->play();
    
    delete game;
    return 0;
}
