//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Tesla.h"

Tesla::Tesla(int x, int y) {
    this-> x= x;
    this->y = y;
}

int Tesla::getX() {
    return x;
}

int Tesla::getY() {
    return y;
}

void Tesla::moveTo(int x, int y) {
    this->x = x;
    this->y = y;
    battery--;
}

void Tesla::charge() {
    battery += 10;

    if (battery > 100) { // don't allow overcharing
        battery = 100;
    }
}

int Tesla::getBattery() const {
    return battery;
}

