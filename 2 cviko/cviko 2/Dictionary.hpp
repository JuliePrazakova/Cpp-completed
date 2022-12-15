//
//  Dictionary.hpp
//  cviko 2
//
//  Created by Julie Pražáková on 11.12.2022.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp
#include <iostream>
#include "Word.hpp"
#include <vector>
#include <stdio.h>

class Dictionary{
    std::vector<Word> m_words;
    
public:
    Dictionary();
    Word findConnectedWord(Word word) const;
    
};


#endif /* Dictionary_hpp */
