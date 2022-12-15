cmake_minimum_required(VERSION 3.17)
project(Chatbot)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chatbot
        chat.txt
        Chatbot.cpp
        Chatbot.hpp
        Conversation.hpp
        Conversation.cpp
        Loader.cpp
        Loader.hpp
        main.cpp)
