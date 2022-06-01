cmake_minimum_required(VERSION 3.21)
project(TRABALHO-2_DA)

set(CMAKE_CXX_STANDARD 14)

include_directories(classes)

add_executable(TRABALHO-2_DA
        main.cpp
        classes/grafo.cpp
        classes/grafo.h
        classes/menu.cpp
        classes/menu.h
        classes/maxHeap.cpp
        classes/maxHeap.h classes/main.cpp)
