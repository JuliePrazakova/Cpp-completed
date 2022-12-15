//
// Created by Ivo Pisařovic on 24/09/2020.
//

#ifndef UNTITLED_TESLA_H
#define UNTITLED_TESLA_H


class Tesla {
private:
    int x;
    int y;
    int battery = 50;
public:
    Tesla(int x, int y);
    static const char symbol = '@';
    int getX();
    int getY();
    void moveTo(int x, int y);
    void charge();
    int getBattery() const;
};


#endif //UNTITLED_TESLA_H
