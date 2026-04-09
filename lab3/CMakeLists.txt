cmake_minimum_required(VERSION 4.1)
project(lab3 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab3
        main.c
        bezier_curve.c
        bezier_curve.h)

target_link_libraries(lab3 gdi32 user32)

set_target_properties(lab3 PROPERTIES WIN32_EXECUTABLE TRUE)