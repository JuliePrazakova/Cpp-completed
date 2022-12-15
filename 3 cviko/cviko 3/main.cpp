//
//  main.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include <iostream>
#include "Loader.hpp"
#include "Chatbot.hpp"

int main(int argc, const char * argv[]) {
// --- prvne zkousim samostatne loader a odladim ho ---
//    Loader pokus;
//    std::vector<Conversation> conversations = pokus.getConversations("chat.txt");
//
//    for(auto conv : conversations){
//        std::cout << "R: " << conv.response << std::endl;
//    }

// --- jakmile mam chatbota, zkousim ho jako celek
    Chatbot chatbot("chat.txt");
    chatbot.chat();
    
    return 0;
}
