cmake_minimum_required(VERSION 3.17)
project(CPP_cviceni6_obchod)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPP_cviceni6_obchod
        Customer.h
        CustomerException.h
        Item.h
        main.cpp
        Order.h
        Store.cpp
        Store.h
        StoreException.h
        TestSuite/Suite.cpp
        TestSuite/Suite.h
        TestSuite/Test.cpp
        TestSuite/Test.h
        StoreTest.cpp
        StoreTest.hpp
        )
