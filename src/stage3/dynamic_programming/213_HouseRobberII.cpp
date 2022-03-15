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
        if (n == 1)
            return nums[0];
        return std::max(robDp(nums, 0, n - 2), robDp(nums, 1, n - 1));
    }

    int robDp(const std::vector<int> &nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1)
            return nums[start];
        int dp[n];
        dp[0] = nums[start], dp[1] = std::max(nums[start], nums[start + 1]);
        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[start + i]);
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
        if (n == 1)
            return nums[0];
        return std::max(robDp(nums, 0, n - 2), robDp(nums, 1, n - 1));
    }

    int robDp(const std::vector<int> &nums, int start, int end) {
        int dp_i = 0, dp_i_1 = 0, dp_i_2 = 0;
        for (int i = start; i <= end; i++) {
            dp_i = std::max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.rob({200, 3, 140, 20, 10}) << std::endl;
    std::cout << s.rob({2, 3, 2}) << std::endl;
    std::cout << s.rob({1, 2, 3, 1}) << std::endl;
    std::cout << s.rob({1, 2, 3}) << std::endl;
    return 0;
}
