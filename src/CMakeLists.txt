cmake_minimum_required(VERSION 4.0)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        cpractice.h
        tests.c
)
add_executable(test
        cpractice.h
        main.c
)