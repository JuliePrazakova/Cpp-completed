//
//  Dictionary.cpp
//  cviko 2
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include "Dictionary.hpp"

Dictionary::Dictionary(){
    //musime naplnit slovnik nejakymi slovy
    m_words = {
               Word("gazela"),
               Word("hroch"),
               Word("zebra")
       };
}
Word Dictionary::findConnectedWord(Word word) const{
    //projdu vsechno slova v m_words
    for (auto& systemWord: m_words) {
        
            //jestli se prohledavane slovo da propojit se slovem od hrace
           if (systemWord.isConnectedTo(word)) {
               
               //tak vypnu hledani a vratim slovo
               return systemWord;
           }
       }
        //konec hry, nemame odpoved na hracovo slovo
       return Word("", false);
}
