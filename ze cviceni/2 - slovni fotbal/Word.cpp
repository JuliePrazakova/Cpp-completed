//
// Created by Ivo Pisařovic on 01/10/2020.
//

#include "Word.h"

Word::Word(std::string word, bool isFound) {
    this->word = word;
    this->isFound = isFound;
}

bool Word::isConnectedTo(const Word anotherWord) const {
    return getFirstCharacter() == anotherWord.getLastCharacter();
}

std::string Word::getWord() const {
    return word;
}

bool Word::notFound() const {
    return !isFound;
}

char Word::getFirstCharacter() const {
    return this->word.at(0);
}

char Word::getLastCharacter() const {
    size_t size = this->word.size();
    return this->word.at(size - 1);
}




/*
 * std::string a = "ahoj";
 *
 * std::string b = "a";
 *
 * a.at(0) = 'z';
 *
 * std::cout << a; // zhoj
 * std::cout << b; // zhoj
 *
 *
 */