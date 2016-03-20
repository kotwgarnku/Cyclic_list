cmake_minimum_required(VERSION 3.3)

project(Cyclic_list)

add_definitions(-std=c++11)

set(HEADER_FILES
    Cyclic_list.h)

set(SOURCE_FILES
    Cyclic_list.cpp)

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})
