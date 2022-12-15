//
//  Chatbot.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Chatbot.hpp"

Chatbot::Chatbot(const std::string filename){
    Loader* loader = new Loader();
    m_conversations = loader->getConversations(filename);
}

void Chatbot::chat() const {
    Conversation * conversation = new Conversation();
    std::string userSentence = getUserSentence();
    std::string computerAnswer = ""; //pomocna promenna
    
    while(userSentence != "konec"){
        computerAnswer = findAnswer(userSentence);
        printAnswer(computerAnswer);
        userSentence = getUserSentence();
    }
}

std::string Chatbot::getUserSentence() const {
    std::string sentence;
    
    std::cout << "Zadejte vetu: ";
    getline(std::cin, sentence); //BACHA MUSI BYT GETLINE ZNOVA!
    
    return sentence;
}

std::string Chatbot::findAnswer(const std::string userSentence) const {
    for(auto conversation: m_conversations) {               // prohledam vektor konverzaci
           if (conversation.matches(userSentence)) {        // jestli se conversation matchne s uzivatelovou vetou
               return conversation.response;                // vratim odpoved tohoto KEY slova
           }
       }
    
    return "Nedokazi odpovedet.";
}

void Chatbot::printAnswer(const std::string computerAnswer) const {
    std::cout << "Odpoved zni: " << computerAnswer << std::endl;
}
