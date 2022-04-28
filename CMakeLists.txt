cmake_minimum_required(VERSION 3.20)
project(ex1_mtm C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(tests)

add_executable(AsciiArtTool
        RLEList.c
        RLEList.h
        tool/AsciiArtTool.h
        tool/AsciiArtTool.c
        tool/main.c)
