cmake_minimum_required(VERSION 3.12)
project(dtable C)

set(CMAKE_C_STANDARD 99)

add_library(dtable dtable.c)
add_executable(test_runner test/runner.c)
target_link_libraries(test_runner dyn_table)
