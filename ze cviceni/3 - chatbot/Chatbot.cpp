//
//  Chatbot.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Chatbot.hpp"

Chatbot::Chatbot(const std::string filename){
    Loader loader;
    m_conversations = loader.getConversations(filename);
}

void Chatbot::chat() const{
    std::string userSentence = getUserSentence();
    std::string computerAnswer = "";
    
    while (userSentence != "konec") {
        computerAnswer = findAnswer(userSentence);
        printAnswer(computerAnswer);
        userSentence = getUserSentence();
    }
}

std::string Chatbot::getUserSentence() const{
    std::string sentence = "";
    std::cout << "Zadej vetu: ";
    getline(std::cin, sentence);
    return sentence;
}

std::string Chatbot::findAnswer(const std::string userSentence) const {
    for(auto conversation: m_conversations) {
        if (conversation.matches(userSentence)) {
            return conversation.response;
        }
    }

    return "Nedokazi odpovedet.";
}

void Chatbot::printAnswer(const std::string computerAnswer) const{
    std::cout << "Odpoved pocitace je: " << computerAnswer << std::endl;
}
