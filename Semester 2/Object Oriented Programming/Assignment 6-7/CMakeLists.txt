
cmake_minimum_required(VERSION 3.27)
project(oop_a6_7_antoniab16)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_a6_7_antoniab16
        src/controller.cpp
        src/controller.h
        src/dynamic_array.cpp
        src/dynamic_array.h
        src/main.cpp
        src/movies.cpp
        src/movies.h
        src/repository.cpp
        src/repository.h
        src/tests.cpp
        src/tests.h
        src/ui.cpp
        src/ui.h
        src/watchlist.cpp
        src/watchlist.h
        src/exceptions.h
        src/exceptions.cpp
        src/exceptions.cpp
        src/validator.h
        src/validator.cpp
        src/file_writer.h
        src/file_writer.cpp
        src/file_repo.h
        src/file_repo.cpp)
