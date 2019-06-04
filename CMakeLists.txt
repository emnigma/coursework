cmake_minimum_required(VERSION 3.13)
project(kursovaya2 C)

set(CMAKE_C_STANDARD 99)

add_executable(kursovaya2 main.c list.h item.h list.c file_manager.h file_manager.c menu.h menu.c checks.h checks.c search.h search.c sort.h sort.c)