//
//  Word.cpp
//  cviko 2
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include "Word.hpp"

Word::Word(std::string word, bool isFound) {
    this->word = word;
    this->isFound = isFound;
}

bool Word::isConnectedTo(const Word anotherWord) const {
    //true pokud prvni pismeno uzivatelova slova == posledni pismeno naseho slova
    return getFirstCharacter() == anotherWord.getLastCharacter();
}

std::string Word::getWord() const {
    return word;
}

bool Word::notFound() const {
    //nenasli jsme shodu pismen = false
    return !isFound;
}

char Word::getFirstCharacter() const {
    //vrat prvni pismeno slova
    return this->word.at(0);
}

char Word::getLastCharacter() const {
    // 1. zjisti velikost slova, 2. vem posledni
    size_t size = this->word.size();
    return this->word.at(size - 1);
}

