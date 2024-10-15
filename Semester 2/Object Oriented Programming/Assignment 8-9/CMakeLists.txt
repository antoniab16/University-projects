cmake_minimum_required(VERSION 3.27)
project(oop_a8_9_antoniab16)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(oop_a8_9_antoniab16
        src/controller.cpp
        src/controller.h
        src/dynamic_array.cpp
        src/dynamic_array.h
        src/exceptions.cpp
        src/exceptions.h
        src/file_writer.cpp
        src/file_writer.h
        src/main.cpp
        src/movies.cpp
        src/movies.h
        src/repository.cpp
        src/repository.h
        src/tests.cpp
        src/tests.h
        src/ui.cpp
        src/ui.h
        src/validator.cpp
        src/validator.h
        src/watchlist.cpp
        src/watchlist.h
        src/file_repo.cpp
        src/gui_console.h
        src/gui_console.cpp)

find_package(Qt5Widgets REQUIRED)
target_link_libraries(oop_a8_9_antoniab16 Qt5::Widgets)
set(CMAKE_AUTOMOC ON)