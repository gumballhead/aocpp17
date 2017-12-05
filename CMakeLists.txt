cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

project(aocpp17)
include_directories("${PROJECT_SOURCE_DIR}/lib/range-v3/include")

add_subdirectory("${PROJECT_SOURCE_DIR}/day1")
add_subdirectory("${PROJECT_SOURCE_DIR}/day2")
add_subdirectory("${PROJECT_SOURCE_DIR}/day4")
