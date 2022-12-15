#include "Conversation.hpp"

bool Conversation::matches(std::string userSentence) {
    // Kdo je petr?
    // .*petr.*
    // regex_match -> true

    return std::regex_match(userSentence, keyword);
}