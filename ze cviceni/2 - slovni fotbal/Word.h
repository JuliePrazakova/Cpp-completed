//
// Created by Ivo Pisařovic on 01/10/2020.
//

#ifndef CV2_WORD_H
#define CV2_WORD_H

#include <string>

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


#endif //CV2_WORD_H
