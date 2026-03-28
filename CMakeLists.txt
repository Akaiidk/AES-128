cmake_minimum_required(VERSION 4.0)
project(aes_implementation C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(aes_implementation
        include/gf2^8.h
        src/aes.c
        src/gf2^8.c)
