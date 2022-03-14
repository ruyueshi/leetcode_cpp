/**
 * 198. House Robber
 * Source: https://leetcode-cn.com/problems/house-robber/
 */

#include <iostream>
#include <vector>

// 动态规划
class SolutionV1 {
public:
    int rob(std::vector<int> &&nums) {
        int n = nums.size();
        if (n < 2)
            return nums[0];
        int dp[n];
        dp[0] = nums[0], dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);  // 不打劫和打劫
        }
        return dp[n - 1];
    }
};

// 优化V1
// 压缩空间
class SolutionV2 {
public:
    int rob(std::vector<int> &&nums) {
        int n = nums.size();
        if (n < 2)
            return nums[0];
        int dp0 = nums[0], dp1 = std::max(nums[0], nums[1]), dp2 = dp1;
        for (int i = 2; i < n; i++) {
            dp2 = std::max(dp1, dp0 + nums[i]);  // 不打劫和打劫
            dp0 = dp1, dp1 = dp2;
        }
        return dp2;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.rob({1, 2, 3, 1}) << std::endl;
    std::cout << s.rob({2, 7, 9, 3, 1}) << std::endl;
    return 0;
}
