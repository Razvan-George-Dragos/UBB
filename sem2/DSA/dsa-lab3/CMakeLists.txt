cmake_minimum_required(VERSION 3.21)
project(dsa_lab3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dsa_lab3
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMIterator.cpp
        SMIterator.h
        SortedMap.cpp
        SortedMap.h)
