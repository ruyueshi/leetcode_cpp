/*
 * 16. 3Sum Closes
 * Source: https://leetcode-cn.com/problems/3sum-closest/
 */

#ifndef SOLUTION016_H
#define SOLUTION016_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

class solution016 {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int min_sum = nums[0] + nums[1] + nums[2];
        int min_dist = std::abs(min_sum - target);
        int length = nums.size();

        for (int i = 0; i < length - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1; j < length - 1; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                for (int k = j + 1; k < length; k++) {
                    if (k > j + 1 && nums[k] == nums[k-1]) {
                        continue;
                    }
                    int current_sum = nums[i] + nums[j] + nums[k];
                    int current_dist = std::abs(current_sum - target);
                    if (current_dist < min_dist) {
                        min_dist = current_dist;
                        min_sum = current_sum;
                    }
                }
            }
        }

        return min_sum;
    }
};

void test_solution016() {
    solution016 s;
    std::vector<int> nums = {-1,2,1,-4};
    int target = 1;
    std::cout << s.threeSumClosest(nums, target) << std::endl;
}

#endif // SOLUTION016_H
