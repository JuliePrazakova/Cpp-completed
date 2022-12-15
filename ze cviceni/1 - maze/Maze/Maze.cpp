//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Maze.h"
#include <iostream>

Maze::Maze() {
    worm = new Worm(3, 3);
    plan = std::array<std::array<char, 5>, 5>();

    for (auto &row: plan) { // auto -> array<char, 5>
        for (auto &column: row) { // auto -> char
            column = '-';
        }
    }
}

void Maze::print() const {
    for (int y = 0; y < plan.size(); y++) {
        for (int x = 0; x < plan.at(y).size(); x++) {
            if (worm->getX() == x and worm->getY() == y) {
                std::cout << Worm::symbol;
            } else {
                std::cout << plan.at(x).at(y);
            }
        }
        std::cout << std::endl;
    }
}

void Maze::moveWorm(const int x, const int y) {
    worm->moveTo(worm->getX() + x, worm->getY() + y);
}

bool Maze::checkDirection(const int x, const int y) const {
    int newX = worm->getX() + x;
    int newY = worm->getY() + y;

    return (
        newX >= 0 and
        newX < plan.at(0).size() and
        newY >= 0 and
        newY < plan.size()
    );
}
