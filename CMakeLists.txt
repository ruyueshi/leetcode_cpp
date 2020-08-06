cmake_minimum_required(VERSION 3.17)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/src)

aux_source_directory(${PROJECT_SOURCE_DIR}/src src_list)

add_executable(leetcode_cpp ${src_list} src/solution014.h)