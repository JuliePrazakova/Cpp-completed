//
//  Loader.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Loader.hpp"

std::vector<Conversation> Loader::getConversations(const std::string filename) const{
    std::vector<Conversation> conversations;
    std::string row = "";
    
    // otevru soubor
    std::ifstream in(filename);
    // kontrola otevreni
    if (in.is_open()){
        // nactu radek
        while(getline(in, row)){
            // rozdelim radek
            Conversation con = splitLine(row);
            // ulozim do vektoru
            conversations.push_back(con);
        }
    } else {
        std::cerr << "Pozor, nenacetli jsme soubor" << std::endl;
    }
    
    return conversations;
}

Conversation Loader::splitLine(const std::string line) const{
    long position = line.find(" ");

    std::string answer = line.substr(position+1, line.size()-position-1);
    std::regex exp(".*" + line.substr(0, position) + ".*");

    return Conversation{exp, answer};
}
