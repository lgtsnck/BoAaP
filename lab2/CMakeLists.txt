cmake_minimum_required(VERSION 4.1)
project(lab2 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab2
        main.c
        house.c
        house.h
        vw_logo.c
        vw_logo.h
        scene.c
        scene.h)

target_link_libraries(lab2 gdi32 user32)

set_target_properties(lab2 PROPERTIES WIN32_EXECUTABLE TRUE)