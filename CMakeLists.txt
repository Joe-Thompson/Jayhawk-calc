cmake_minimum_required(VERSION 3.20)
project(Jayhawk_calc C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Jayhawk_calc
        CartV1.c
        CartV2.c
        CartV3.c
        CartV4.c)
