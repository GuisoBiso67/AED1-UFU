cmake_minimum_required(VERSION 3.31)
project(Pratica06 C)

set(CMAKE_C_STANDARD 11)

include_directories(ex003)

add_executable(Pratica06
        ex003/main.c
        ex003/functions.c
        ex003/functions.h)
