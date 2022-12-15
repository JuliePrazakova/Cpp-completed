//
//  Word.hpp
//  cviko 2
//
//  Created by Julie Pražáková on 11.12.2022.
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>
#include <iostream>

class Word {
private:
    std::string word;
    bool isFound;
    char getLastCharacter() const;
    char getFirstCharacter() const;
public:
    Word(std::string word, bool isFound = true);
    bool isConnectedTo(Word anotherWord) const;
    bool notFound() const;
    std::string getWord() const;
};

#endif /* Word_hpp */
