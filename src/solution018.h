/**
 * 18. 4Sum
 * Source: https://leetcode-cn.com/problems/4sum/
 */

#ifndef SOLUTION018_H
#define SOLUTION018_H

#include "timer.h"

#include <iostream>
#include <vector>
#include <algorithm>

class solution018 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        int length = nums.size();

        for (int i = 0; i < length - 3; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int l = length - 1;
                for (int k = j + 1; k < length - 1; k++) {
                    if (k > j + 1 && nums[k] == nums[k-1]) {
                        continue;
                    }
                    while (k < l && nums[i] + nums[j] + nums[k] + nums[l] > target) {
                        l--;
                    }
                    if (l == k) {
                        break;
                    }
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }

        return ans;
    }
};

static void test_solution018() {
    solution018 s;
    int target = -11;
//    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    std::vector<int> nums = {1,-2,-5,-4,-3,3,3,5};

    timer t;
    std::vector<std::vector<int>> ans = s.fourSum(nums, target);
    t.cost();
    std::cout << "ans = " << std::endl;
    for (auto &vec : ans) {
        for (auto &i : vec) {
            std::cout << i << ",";
        }
        std::cout << std::endl;
    }
}

#endif // SOLUTION018_H
