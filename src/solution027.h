/**
 * 27. Remove Element
 * Source: https://leetcode-cn.com/problems/remove-element/
 */

#ifndef SOLUTION027_H
#define SOLUTION027_H

#include <iostream>
#include <vector>

class solution027 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int total = static_cast<int>(nums.size());
        for (unsigned i = 0; i < nums.size();) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                total--;
            } else {
                i++;
            }
        }
        return total;
    }
};

void test_solution027() {
    solution027 s;
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int total = s.removeElement(nums, val);
    for (auto& n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl << "total: " << total << std::endl;
}


#endif // SOLUTION027_H
