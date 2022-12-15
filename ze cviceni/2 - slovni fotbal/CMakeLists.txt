cmake_minimum_required(VERSION 3.17)
project(cv2)

set(CMAKE_CXX_STANDARD 11)

add_executable(cv2 main.cpp Game.cpp Game.h Word.cpp Word.h Dictionary.cpp Dictionary.h)