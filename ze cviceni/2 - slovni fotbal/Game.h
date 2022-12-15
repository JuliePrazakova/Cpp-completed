//
// Created by Ivo Pisařovic on 01/10/2020.
//

#ifndef CV2_GAME_H
#define CV2_GAME_H


#include "Dictionary.h"
#include "Word.h"

class Game {
private:
    Dictionary* dictionary;

    void printIntroduction() const;
    void printSystemWord(Word word) const;
    Word waitForInput() const;
    void printEndOfGame() const;
    void processSystemWord(Word systemWord) const;
public:
    Game();
    void play();
    void end() const;

};


#endif //CV2_GAME_H
