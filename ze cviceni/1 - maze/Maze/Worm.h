//
// Created by Ivo Pisařovic on 24/09/2020.
//

#ifndef UNTITLED_WORM_H
#define UNTITLED_WORM_H


class Worm {
private:
    int x;
    int y;
public:
    Worm(int x, int y);
    static const char symbol = '@';
    int getX();
    int getY();
    void moveTo(int x, int y);
};


#endif //UNTITLED_WORM_H
