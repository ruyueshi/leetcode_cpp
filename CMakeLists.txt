cmake_minimum_required(VERSION 3.0)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/utils
        ${PROJECT_SOURCE_DIR}/stage1
)

#aux_source_directory(${PROJECT_SOURCE_DIR}/src src_list)

# stage1
add_executable(leetcode_cpp src/stage1/main.cpp)

# stage2
add_executable(solution029 src/stage2/solution029.cpp)
add_executable(solution030 src/stage2/solution030.cpp)
add_executable(solution031 src/stage2/solution031.cpp)