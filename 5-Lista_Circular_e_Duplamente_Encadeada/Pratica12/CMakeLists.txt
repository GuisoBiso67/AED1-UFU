cmake_minimum_required(VERSION 3.31)
project(Pratica12 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Pratica12
        main.c
        playlist.c
        playlist.h
        cmake-build-debug/musicas.txt)
