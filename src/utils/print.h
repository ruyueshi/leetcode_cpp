#ifndef LEETCODE_CPP_PRINT_H
#define LEETCODE_CPP_PRINT_H

#include <iostream>
#include <vector>

// print output result
template<typename T>
static void print_vector(std::vector<T> nums) {
    for (const auto &i: nums)
        std::cout << i << ",";
    std::cout << "\b\n";
}

// debug in recursion
static void print_indent(int n) {
    for (int i = 0; i < n; i++) {
        printf("   ");
    }
}

#endif //LEETCODE_CPP_PRINT_H
