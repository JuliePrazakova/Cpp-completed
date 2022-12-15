//
// Created by Ivo Pisařovic on 06.10.2021.
//

#include "Dictionary.h"

Dictionary::Dictionary() {
    words = {
            Word("gazela"),
            Word("hroch"),
            Word("zebra")
    };
}

Word Dictionary::findConnectedWord(Word word) const {
    for (auto& systemWord: words) {
        if (systemWord.isConnectedTo(word)) {
            return systemWord;
        }
    }

    return Word("", false);
}


