//
//  Game.hpp
//  cviko 2
//
//  Created by Julie Pražáková on 11.12.2022.
//

#ifndef Game_hpp
#define Game_hpp

#include "Dictionary.hpp"
#include "Word.hpp"
#include <stdio.h>

class Game {
    Dictionary* dictionary;
    
    void printIntroduction() const;
    void printSystemWord(class Word word) const;
    Word waitForInput() const;
    void printEndOfGame() const;
    void processSystemWord(class Word systemWord) const;
    
public:
    Game();
    void play() ;
    void end() const;
    
    
    
};

#endif /* Game_hpp */
