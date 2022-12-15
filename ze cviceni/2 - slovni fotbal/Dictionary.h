//
// Created by Ivo Pisařovic on 06.10.2021.
//

#ifndef CV2_DICTIONARY_H
#define CV2_DICTIONARY_H

#include <vector>
#include "Word.h"

class Dictionary {
private:
    std::vector<Word> words;
public:
    Dictionary();
    Word findConnectedWord(Word word) const;
};


#endif //CV2_DICTIONARY_H
