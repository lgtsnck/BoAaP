cmake_minimum_required(VERSION 4.1)
project(lab11 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab11 main.c
        text_processor.c
        text_processor.h
)
