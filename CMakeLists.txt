cmake_minimum_required(VERSION 3.7)
project(task6_sum_of_it_parts)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
src/main.cpp
src/parts.h
src/parts.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/definitions.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/queries.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(task6_sum_of_it_parts ${SOURCE_FILES})