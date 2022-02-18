#ifndef LEETCODE_CPP_PRINT_H
#define LEETCODE_CPP_PRINT_H

#include <iostream>
#include <vector>

template<typename T>
static void print_vector(std::vector<T> nums) {
    for (auto &i: nums)
        std::cout << i << ",";
    std::cout << "\b\n";
}

#endif //LEETCODE_CPP_PRINT_H
