/**
 * 53. Maximum Subarray
 * Source: https://leetcode-cn.com/problems/maximum-subarray/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(const std::vector<int> &nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            res = std::max(res, dp[i]);
        }
        return res;
    }

    // 空间压缩
    int maxSubArray_V2(const std::vector<int> &nums) {
        int n = nums.size();
        int pre = nums[0];
        int res = pre;
        for (int i = 1; i < n; i++) {
            pre = std::max(pre + nums[i], nums[i]);
            res = std::max(res, pre);
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.maxSubArray_V2({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << std::endl;
    std::cout << s.maxSubArray({1}) << std::endl;
    std::cout << s.maxSubArray_V2({5, 4, -1, 7, 8}) << std::endl;
    return 0;
}
