include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        methods_check.cpp)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests src)
