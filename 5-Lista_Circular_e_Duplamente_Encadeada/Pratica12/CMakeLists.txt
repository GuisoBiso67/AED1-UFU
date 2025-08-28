cmake_minimum_required(VERSION 3.31)
project(Pratica12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pratica12
        main.c
        musicas2.txt
        playlist.c
        playlist.h)
