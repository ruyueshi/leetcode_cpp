cmake_minimum_required(VERSION 2.8)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/include
)

aux_source_directory(${PROJECT_SOURCE_DIR}/src src_list)

add_executable(leetcode_cpp src/main.cpp)
add_executable(solution029 src/solution029.cpp)