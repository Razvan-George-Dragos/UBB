cmake_minimum_required(VERSION 3.21)
project(dsa_lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dsa_lab1
        App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
