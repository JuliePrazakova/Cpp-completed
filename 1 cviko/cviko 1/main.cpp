//
//  main.cpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    Game* game = new Game();
    game->start();
    
    return 0;
}
