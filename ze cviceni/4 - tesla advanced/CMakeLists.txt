cmake_minimum_required(VERSION 3.23)
project(intermediate)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(intermediate
        Game.cpp
        Game.h
        main.cpp
        Map.cpp
        Map.h
        Tesla.cpp
        Tesla.h)
