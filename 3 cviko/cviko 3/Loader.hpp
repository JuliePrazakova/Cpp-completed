//
//  Loader.hpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#ifndef Loader_hpp
#define Loader_hpp

#include <iostream>
#include <vector>
#include <fstream>

#include "Conversation.hpp"

class Loader{
public:
    Loader(){}
    //funkce co nacte vety ze souboru do vektoru <conversations>
    std::vector<Conversation> getConversations(const std::string filename) const;
private:
    //rozreze radek na slova
    Conversation splitLine(const std::string line) const;
};


#endif /* Loader_hpp */
