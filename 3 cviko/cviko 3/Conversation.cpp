#include "Conversation.hpp"


bool Conversation::matches(std::string userSentence) {
    
    //vrati true pokud najde shodu
    return std::regex_match(userSentence, keyword);
}

//userSentence je jasny ten je dosazeny, ale kde bere keyword - pri volani musi byt nejaky look ktery projde vsechny keywordy a zavola u nich tuto funkci
