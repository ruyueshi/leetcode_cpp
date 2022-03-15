/**
 * 15. 3Sum
 * Source: https://leetcode-cn.com/problems/3sum/
 */

#include <algorithm>
#include <iostream>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &&nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0)  // 剪枝（仅适用于target非负的时候）
                break;
            if (i > 0 && nums[i] == nums[i - 1])  // 去重
                continue;
            int target = 0 - nums[i];
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[low] + nums[high];
                int left_value = nums[low], right_value = nums[high];
                if (sum < target) {
                    while (low < high && nums[low] == left_value)
                        low++;
                } else if (sum > target) {
                    while (low < high && nums[high] == right_value)
                        high--;
                } else {
                    res.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == left_value)
                        low++;
                    while (low < high && nums[high] == right_value)
                        high--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    auto res = s.threeSum({-1, 0, 1, 2, -1, -4});
    for (auto &v: res) {
        print_vector(v);
    }
    std::cout << s.threeSum({0}).size() << ", " << s.threeSum({}).size() << std::endl;
    return 0;
}
