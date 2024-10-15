cmake_minimum_required(VERSION 3.27)
project(t1_antoniab16_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1_antoniab16_1
        main.cpp
        dynamic_vector.h
        schools.h
        ui.h
        ui.cpp
        schools.cpp
        repository.h
        repository.cpp
        controller.h
        controller.cpp
        tests.h
        tests.cpp)
