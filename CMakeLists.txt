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

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/documentacao/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/documentacao/Doxyfile.txt")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
    else(DOXYGEN_FOUND)
        message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)