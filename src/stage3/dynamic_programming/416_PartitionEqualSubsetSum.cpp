/**
 * 416. Partition Equal Subset Sum
 * Source: https://leetcode-cn.com/problems/partition-equal-subset-sum/
 */

#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int> &nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        return subsets_v2(nums, sum / 2);
    }

private:
    bool subsets(const std::vector<int> &nums, int target) {
        int n = nums.size();
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }

    // 压缩空间
    bool subsets_v2(const std::vector<int> &nums, int target) {
        int n = nums.size();
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 1; j--) {
                if (nums[i - 1] <= j)
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 5, 11, 5};
    std::cout << s.canPartition(nums) << std::endl;
    nums = {1, 2, 3, 5};
    std::cout << s.canPartition(nums) << std::endl;
    return 0;
}
