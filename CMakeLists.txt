cmake_minimum_required(VERSION 3.3)
project(Cyclic_list)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(src_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(src_run src)
