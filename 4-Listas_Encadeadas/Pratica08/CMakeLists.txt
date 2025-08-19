cmake_minimum_required(VERSION 3.31)
project(Pratica08 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Pratica08
        functions.c
        functions.h
        main.c)
