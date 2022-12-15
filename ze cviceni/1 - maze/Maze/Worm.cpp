//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Worm.h"

Worm::Worm(int x, int y) {
    this-> x= x;
    this->y = y;
}

int Worm::getX() {
    return x;
}

int Worm::getY() {
    return y;
}

void Worm::moveTo(int x, int y) {
    this->x = x;
    this->y = y;
}
