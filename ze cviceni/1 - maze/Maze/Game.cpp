//
// Created by Ivo Pisařovic on 01/10/2020.
//

#include "Game.h"

//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Maze.h"
#include <iostream>

Game::Game() {
    maze = new Maze();
}

void Game::printIntroduction() const {
    std::cout << "Game started." << std::endl;
}

void Game::printOptions() const {
    std::cout << "Press WASD to move the worm." << std::endl;
}

char Game::waitForInput() const {
    char input;
    std::cin >> input;
    return input;
}

void Game::printEnd() const {
    std::cout << "Game ended" << std::endl;
}

void Game::start() {
    printIntroduction();

    while (true) {
        maze->print();
        printOptions();
        char input = waitForInput();
        processInput(input);
    }
}

void Game::processInput(char input) {
    if (input == 'q') {
        printEnd();
        exit(0);
    } else if (input == 'a') {
        tryMovingWorm(-1, 0);
    } else if (input == 'd') {
        tryMovingWorm(1, 0);
    } else if (input == 'w') {
        tryMovingWorm(0, -1);
    } else if (input == 's') {
        tryMovingWorm(0, 1);
    } else {
        std::cout << "Unsupported option!" << std::endl;
    }
}

void Game::tryMovingWorm(int x, int y) {
    if (maze->checkDirection(x, y)) {
        maze->moveWorm(x, y);
    } else {
        std::cout << "You just hit the wall! Take care ;)" << std::endl;
    }
}



