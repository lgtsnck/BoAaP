cmake_minimum_required(VERSION 4.1)
project(lab6 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab6 main.c
        array_logic.c
        array_logic.h
        visual.c
        visual.h)

target_link_libraries(lab6 gdi32 user32)