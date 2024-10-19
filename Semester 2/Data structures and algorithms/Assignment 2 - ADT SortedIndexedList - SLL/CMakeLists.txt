cmake_minimum_required(VERSION 3.29)
project(a2___SortedIndexedList___SLL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a2___SortedIndexedList___SLL
        "ExtendedTest.cpp"
        "ExtendedTest.h"
        "ListIterator.cpp"
        "ListIterator.h"
        "ShortTest.cpp"
        "ShortTest.h"
        "SortedIndexedList.h"
        "SortedIndexeList.cpp"
        App.h
        App.cpp)
