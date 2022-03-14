/**
 * 198. House Robber
 * Source: https://leetcode-cn.com/problems/house-robber/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int> &&nums) {
        int n = nums.size();
        int dp[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i] = nums[0];
            } else if (i == 1) {
                dp[i] = std::max(nums[0], nums[1]);
            } else if (i == 2) {
                dp[i] = std::max(dp[1], nums[2]);
            } else if (i == 3) {
                dp[i] = std::max(nums[0] + nums[2], nums[1] + nums[3]);
            } else {
                dp[i] = std::max(std::max(dp[i - 1], dp[0]), std::max(dp[i - 2] + nums[i], dp[1] + nums[i]));
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    std::cout << s.rob({200, 3, 140, 20, 10}) << std::endl;
    std::cout << s.rob({2, 3, 2}) << std::endl;
    std::cout << s.rob({1, 2, 3, 1}) << std::endl;
    std::cout << s.rob({1, 2, 3}) << std::endl;
    return 0;
}
