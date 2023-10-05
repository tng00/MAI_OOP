cmake_minimum_required(VERSION 3.10)
project(LAB1)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
add_executable(${PROJECT_NAME} main.cpp)

enable_testing()
add_executable(test1 test.cpp)
target_link_libraries(test1 gtest_main gmock_main)
add_test(NAME BASIC COMMAND test1)
