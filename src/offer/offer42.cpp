/**
 * offer 42. 连续子数组的最大和
 * Source: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        int cur = nums[0], max_value = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (cur <= 0)
                cur = nums[i];
            else
                cur += nums[i];
            max_value = std::max(max_value, cur);
        }
        return max_value;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << s.maxSubArray(nums) << std::endl;
    nums = {8, -19, 5, -4, 20};
    std::cout << s.maxSubArray(nums) << std::endl;
    nums = {-2, 1};
    std::cout << s.maxSubArray(nums) << std::endl;
    return 0;
}
