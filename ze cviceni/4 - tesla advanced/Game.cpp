#include <iostream>
#include "Game.h"
#include "Map.h"

Game::Game() {
    map = new Map();
}

void Game::printIntroduction() const {
    std::cout << "Game started." << std::endl;
}

void Game::printOptions() const {
    std::cout << "Press WASD to move the Tesla." << std::endl;
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
        map->print();
        map->printTeslaInfo();
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
        tryMovingTesla(-1, 0);
    } else if (input == 'd') {
        tryMovingTesla(1, 0);
    } else if (input == 'w') {
        tryMovingTesla(0, -1);
    } else if (input == 's') {
        tryMovingTesla(0, 1);
    } else {
        std::cout << "Unsupported option!" << std::endl;
    }
}

void Game::tryMovingTesla(int x, int y) {
    if (map->checkDirection(x, y)) {
        map->moveTesla(x, y);
    } else {
        std::cout << "You just hit the wall! Take care ;)" << std::endl;
    }
}



