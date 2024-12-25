cmake_minimum_required(VERSION 3.29)
project(CP_8 C)

set(CMAKE_C_STANDARD 23)

add_executable(CP_8 main.c
        print_electric_circuit.h
        calculation.h
        input.h)
