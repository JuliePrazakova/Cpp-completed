//
//  Chatbot.hpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#ifndef Chatbot_hpp
#define Chatbot_hpp

#include <vector>
#include "Loader.hpp"
#include "Conversation.hpp"

class Chatbot {
    std::vector<Conversation> m_conversations;
    
public:
    Chatbot(const std::string filename);
    void chat() const;
private:
    std::string getUserSentence() const;
    std::string findAnswer(const std::string userSentence) const;
    void printAnswer(const std::string computerAnswer) const;
};
#endif /* Chatbot_hpp */
