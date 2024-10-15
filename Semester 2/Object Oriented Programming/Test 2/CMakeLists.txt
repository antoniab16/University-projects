cmake_minimum_required(VERSION 3.27)
project(oop_t2_antoniab16)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_t2_antoniab16
        main.cpp
        engine.h
        engine.cpp
        car.h
        car.cpp
        service.h
        service.cpp
        ui.h
        ui.cpp)
