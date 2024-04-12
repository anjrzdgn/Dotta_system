cmake_minimum_required(VERSION 3.27)
project(dotta)

set(CMAKE_CXX_STANDARD 14)

add_executable(dotta
        main.cpp
        universal_header.h
        UI_UX_function.cpp
        UI_UX_header.h
        dotta_identified_classes.h
        main_menu_and_belonging_functions.cpp
        main_menu_and_belonging_header.h
        online_user_variable_header.h
        command_and_check_function.cpp
        command_and_check_header.h
        online_user_variable_source.cpp
        RAM_courses_function.cpp
        RAM_courses_header.h
        RAM_HW_functions.cpp
        RAM_HW_header.h
)