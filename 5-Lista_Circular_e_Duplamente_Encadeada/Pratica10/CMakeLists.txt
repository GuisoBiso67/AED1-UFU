cmake_minimum_required(VERSION 3.31)
project(Pratica10 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Pratica10
        functions.c
        functions.h
        prat10.c)
