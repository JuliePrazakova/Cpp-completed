#include "Map.h"
#include <iostream>

Map::Map() {
    tesla = new Tesla(3, 3);
    plan = std::array<std::array<char, 5>, 5>();

    for (auto &row: plan) { // auto -> array<char, 5>
        for (auto &column: row) { // auto -> char
            column = '-';
        }
    }
    
    plan.at(1).at(1) = '+';
    plan.at(2).at(4) = '+';
    plan.at(4).at(2) = '+';
    
}

void Map::print() const {
    for (int y = 0; y < plan.size(); y++) {
        for (int x = 0; x < plan.at(y).size(); x++) {
            if (tesla->getX() == x and tesla->getY() == y) {
                std::cout << Tesla::symbol;
            } else {
                std::cout << plan.at(x).at(y);
            }
        }
        std::cout << std::endl;
    }
}

void Map::printTeslaInfo() const {
    std::cout << "Battery: " << tesla->getBattery() << "%" << std::endl;
}

void Map::moveTesla(const int x, const int y) {
    tesla->moveTo(tesla->getX() + x, tesla->getY() + y);
    
    if (isSupercharger(tesla->getX(), tesla->getY())) {
        tesla->charge();
    }
}

bool Map::isSupercharger(int x, int y) const {
    return plan.at(x).at(y) == '+';
}

bool Map::checkDirection(const int x, const int y) const {
    int newX = tesla->getX() + x;
    int newY = tesla->getY() + y;

    return (
        newX >= 0 and
        newX < plan.at(0).size() and
        newY >= 0 and
        newY < plan.size()
    );
}

char Map::getField(int x, int y) const {
    return plan.at(x).at(y);
}

Tesla* Map::getTesla() const {
    return tesla;
}
