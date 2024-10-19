cmake_minimum_required(VERSION 3.28)
project(assignment_1___bag)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment_1___bag
        App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
