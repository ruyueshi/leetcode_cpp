/**
 * 26. Remove Duplicates from Sorted Array
 * Source: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

#ifndef SOLUTION026_H
#define SOLUTION026_H

#include <iostream>
#include <vector>

class solution026 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        int p = 0;
        for (unsigned q = 1; q < nums.size(); q++) {
            if (nums[p] != nums[q]) {
                nums[++p] = nums[q];
            }
        }
        return p + 1;
    }
};

static void test_solution026() {
    solution026 s;
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int total = s.removeDuplicates(nums);
    for (auto& n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl << "total: " << total << std::endl;
}

#endif // SOLUTION026_H
