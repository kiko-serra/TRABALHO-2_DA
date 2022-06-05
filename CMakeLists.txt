cmake_minimum_required(VERSION 3.21)
project(TRABALHO-2_DA)

set(CMAKE_CXX_STANDARD 14)

include_directories(codigo)

add_executable(TRABALHO-2_DA
        codigo/grafo.cpp
        codigo/grafo.h
        codigo/main.cpp
        codigo/maxHeap.cpp
        codigo/maxHeap.h
        codigo/menu.cpp
        codigo/menu.h)
