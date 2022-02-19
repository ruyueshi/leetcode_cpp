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

# offer
add_executable(offer04 src/offer/offer04.cpp)
add_executable(offer03 src/offer/offer03.cpp)
add_executable(offer05 src/offer/offer05.cpp)
add_executable(offer06 src/offer/offer06.cpp)
add_executable(offer09 src/offer/offer09.cpp)
add_executable(offer10-1 src/offer/offer10-1.cpp)
add_executable(offer10-2 src/offer/offer10-2.cpp)
add_executable(offer11 src/offer/offer11.cpp)
add_executable(offer12 src/offer/offer12.cpp)
add_executable(offer18 src/offer/offer18.cpp)
add_executable(offer21 src/offer/offer21.cpp)
add_executable(offer22 src/offer/offer22.cpp)
add_executable(offer24 src/offer/offer24.cpp)
add_executable(offer25 src/offer/offer25.cpp)
add_executable(offer26 src/offer/offer26.cpp)
add_executable(offer27 src/offer/offer27.cpp)
add_executable(offer28 src/offer/offer28.cpp)
add_executable(offer30 src/offer/offer30.cpp)
add_executable(offer32-1 src/offer/offer32-1.cpp)
add_executable(offer32-2 src/offer/offer32-2.cpp)
add_executable(offer32-3 src/offer/offer32-3.cpp)
add_executable(offer35 src/offer/offer35.cpp)
add_executable(offer42 src/offer/offer42.cpp)
add_executable(offer46 src/offer/offer46.cpp)
add_executable(offer47 src/offer/offer47.cpp)
add_executable(offer48 src/offer/offer48.cpp)
add_executable(offer50 src/offer/offer50.cpp)
add_executable(offer52 src/offer/offer52.cpp)
add_executable(offer53-1 src/offer/offer53-1.cpp)
add_executable(offer53-2 src/offer/offer53-2.cpp)
add_executable(offer57 src/offer/offer57.cpp)
add_executable(offer58-1 src/offer/offer58-1.cpp)
add_executable(offer58-2 src/offer/offer58-2.cpp)
add_executable(offer63 src/offer/offer63.cpp)
