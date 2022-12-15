//
//  Game.cpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include "Game.hpp"
#include <iostream>

Game::Game(){
    maze = new Maze();
}

void Game::printIntroduction(){
    std::cout << "Introduction" << std::endl;
}
void Game::printOptions(){
    std::cout << "Press WASD to move the worm." << std::endl;
    maze->printBatery();
}
char Game::waitForInput(){
    char input;
    std::cin >> input;
    return input;
}
void Game::printEnd(){
    std::cout << "End" << std::endl;
}
void Game::processInput(char input){
    if (input == 'q') {
           printEnd();
           exit(0);
       } else if (input == 'a') { //doleva
           tryMovingTesla(-1, 0);
       } else if (input == 'd') { //doprava
           tryMovingTesla(1, 0);
       } else if (input == 'w') { //nahoru
           tryMovingTesla(0, -1);
       } else if (input == 's') { //dolu
           tryMovingTesla(0, 1);
       } else {
           std::cout << "Unsupported option!" << std::endl;
       }
}
void Game::tryMovingTesla(int x, int y){
    if( maze->checkDirection(x, y)){
        maze->moveTesla(x, y);
    }else{
        std::cout << "Tudy jit nemuzete, tady stena" << std::endl;
    }
}

void Game::start(){
    printIntroduction();
    
    while(true) {
        maze->print();
        printOptions();
        char input = waitForInput();
        processInput(input);
    }
}
