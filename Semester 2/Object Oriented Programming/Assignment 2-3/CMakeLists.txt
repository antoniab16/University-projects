cmake_minimum_required(VERSION 3.27)
project(a2_3_antoniab16 C)

set(CMAKE_C_STANDARD 11)

add_executable(a2_3_antoniab16
        domain.h
        ui.c
        repository.c
        repository.h
        main.c
        ui.h
        controller.c
        controller.h
        dynamic_vector.h
        dynamic_vector.c
        domain.c
        operation_stack.c
        operation_stack.h
)

