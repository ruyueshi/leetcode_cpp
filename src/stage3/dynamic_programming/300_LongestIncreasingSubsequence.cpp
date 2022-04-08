/**
 * 300. Longest Increasing Subsequence
 * Source: https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << s.lengthOfLIS(nums) << std::endl;
    return 0;
}
