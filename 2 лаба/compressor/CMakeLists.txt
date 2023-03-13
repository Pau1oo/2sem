cmake_minimum_required(VERSION 3.23)
project(compressor C)

set(CMAKE_C_STANDARD 99)

add_executable(compressor main.c functions.h functions.c)
