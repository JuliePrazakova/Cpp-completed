//
//  Loader.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Loader.hpp"
#include <iostream>
#include <fstream>


std::vector<Conversation> Loader::getConversations(const std::string filename) const{
    std::vector<Conversation> conversations;

    //pripravim promennou do ktere nahraju radek
    std::string row = "";
 
// NEBO:
//    // 1. otevru soubor
//    std::ifstream file;
//
//    //kontrola otevreni
//    file.open("chat.txt");
    
    // 1. otevru soubor
    std::ifstream file(filename);
    
    if(file.is_open()){
        
        // nactu radek
        while(getline(file, row)){
            
            // rozdelim radek
            Conversation con = splitLine(row);
            
            // ulozim do vektoru
            conversations.push_back(con);
        }
    }else {
        std::cerr << "Pozor, nenacetli jsme soubor" << std::endl;
    }
    
    return conversations;
}

Conversation Loader::splitLine(const std::string line) const{
    // vyhledam pozici (index) 1. mezery = deli KLICOVE SLOVO od ODPOVEDI
    long position = line.find(" ");
    
    // od pozice mezery dal je ODPOVED pokud uzivatel zada klicove slovo
    std::string answer = line.substr(position + 1, line.size() - position - 1);
    
    // vytvorime substring .substr - toho slova na pozici = position (po mezeru)
    // std::regex key(line.substr(0, position));
    std::regex key(".*" + line.substr(0, position) + ".*");
    
    //vrati nam radek zordeleny na KEY a ODPOVED
    return Conversation{key, answer};
}
