cmake_minimum_required(VERSION 3.23)
project(complete)

set(CMAKE_CXX_STANDARD 14)

add_executable(complete
        tests/TestSuite/Suite.cpp tests/TestSuite/Suite.h tests/TestSuite/Test.h tests/TestSuite/Test.cpp tests/RoverTest.hpp tests/RoverTest.cpp
        main.cpp materials/Ice.h materials/Soil.h materials/Water.h materials/Concrete.h Rover.h)
