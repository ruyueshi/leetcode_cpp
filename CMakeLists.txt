cmake_minimum_required(VERSION 3.0)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/utils
        ${PROJECT_SOURCE_DIR}/stage1
)

# stage1
add_executable(leetcode_cpp src/stage1/main.cpp)

# stage2
add_executable(solution029 src/stage2/solution029.cpp)
add_executable(solution030 src/stage2/solution030.cpp)
add_executable(solution031 src/stage2/solution031.cpp)

# stage3
add_executable(509 src/stage3/dynamic_programming/509_FibonacciNumber.cpp)
add_executable(322 src/stage3/dynamic_programming/322_CoinChang.cpp)
add_executable(046 src/stage3/depth_first_search/046_Permutations.cpp)
add_executable(051 src/stage3/depth_first_search/051_NQueens.cpp)
add_executable(111 src/stage3/breadth_first_search/111_MinimumDepthOfBinaryTree.cpp)
add_executable(752 src/stage3/breadth_first_search/752_OpenTheLock.cpp)
add_executable(104 src/stage3/binary_tree/104_MaximumDepthOfBinaryTree.cpp)
add_executable(543 src/stage3/binary_tree/543_DiameterOfBinaryTree.cpp)
add_executable(144 src/stage3/binary_tree/144_BinaryTreePreorderTraversal.cpp)
add_executable(023 src/stage3/linked_lists/023_MergeKSortedLists.cpp)
add_executable(019 src/stage3/linked_lists/019_RemoveNthNodeFromEndOfList.cpp)
add_executable(876 src/stage3/linked_lists/876_MiddleOfTheLinkedList.cpp)
add_executable(141 src/stage3/linked_lists/141_LinkedListCycle.cpp)
add_executable(160 src/stage3/linked_lists/160_IntersectionOfTwoLinkedLists.cpp)
add_executable(200 src/stage3/graph/200_NumberOfIslands.cpp)
add_executable(1254 src/stage3/graph/1254_NumberOfClosedIslands.cpp)

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
