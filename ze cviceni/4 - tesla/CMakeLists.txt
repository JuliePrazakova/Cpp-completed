cmake_minimum_required(VERSION 3.23)
project(complete)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(complete
        Game.cpp
        Game.h
        main.cpp
        MapTest.cpp
        MapTest.hpp
        Map.cpp
        Map.h
        TestSuite/Suite.cpp
        TestSuite/Suite.h
        Tesla.cpp
        Tesla.h
        TestSuite/Test.cpp
        TestSuite/Test.h)
