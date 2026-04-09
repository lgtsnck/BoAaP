cmake_minimum_required(VERSION 4.1)
project(lab12 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab12 main.c
        animal.c
        animal.h)
