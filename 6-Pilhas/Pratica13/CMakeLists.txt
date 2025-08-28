cmake_minimum_required(VERSION 3.31)
project(Pratica13 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Pratica13
        dictionary.c
        dictionary.h
        main.c
        cmake-build-debug/words_list.txt
        cmake-build-debug/phrases.txt
        battery.c
        battery.h)
