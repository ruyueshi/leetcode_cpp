/**
 * 494. Target Sum
 * Source: https://leetcode-cn.com/problems/target-sum/
 */

#include <iostream>
#include <numeric>
#include <vector>

// 回溯
class SolutionV1 {
public:
    int findTargetSumWays(std::vector<int> &nums, int target) {
        n = nums.size();
        res = 0;
        traceback(nums, target, 0);
        return res;
    }

private:
    int res, n;

    void traceback(const std::vector<int> &nums, int target, int i) {
        if (i == n) {
            if (target == 0)
                res++;
            return;
        }

        // +
        traceback(nums, target - nums[i], i + 1);
        // -
        traceback(nums, target + nums[i], i + 1);
    }
};

// 动态规划
class SolutionV2 {
public:
    int findTargetSumWays(std::vector<int> &nums, int target) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (target + sum < 0 || (target + sum) % 2)
            return 0;
        return subset_v2(nums, (target + sum) / 2);
    }

private:
    // 0-1背包问题
    int subset(const std::vector<int> &nums, int target) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));  // dp[i][j] 表示前i个数中目标为j的子集的个数
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] > j) {  // 太大了不能装下
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }

    // 0-1背包问题
    // 压缩空间
    int subset_v2(const std::vector<int> &nums, int target) {
        int n = nums.size();
        std::vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 0; j--) {
                if (nums[i - 1] > j) {  // 太大了不能装下
                    dp[j] = dp[j];
                } else {
                    dp[j] = dp[j] + dp[j - nums[i - 1]];
                }
            }
        }
        return dp[target];
    }
};


int main() {
    SolutionV2 s;
    std::vector<int> nums = {1, 1, 1, 1, 1};
    std::cout << s.findTargetSumWays(nums, 3) << std::endl;
    nums = {1};
    std::cout << s.findTargetSumWays(nums, 1) << std::endl;
    return 0;
}
