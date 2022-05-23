cmake_minimum_required(VERSION 3.21)
project(TRABALHO_2_DA)

set(CMAKE_CXX_STANDARD 14)

include_directories(classes)

add_executable(TRABALHO_2_DA
        classes/autocarro.cpp
        classes/autocarro.h)
