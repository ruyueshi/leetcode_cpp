/**
 * 300. Longest Increasing Subsequence
 * Source: https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

#include <iostream>
#include <vector>

// V1: 动态规划
// 时间复杂度：O(n^2)
class SolutionV1 {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);  // dp[i]：以nums[i]结尾的递增子序列的长度
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

// V2: 二分查找
// 时间复杂度：O(nlogn)
// https://labuladong.github.io/algo/3/24/69/
class SolutionV2 {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> top;
        int heap_num = 0;
        for (int i = 0; i < n; i++) {
            int candi = nums[i];
            int left = 0, right = heap_num;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (top[mid] == candi) {
                    left = mid;
                    break;
                } else if (top[mid] > candi) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left == heap_num) {
                heap_num++;
                top.push_back(candi);
            } else
                top[left] = candi;
        }
        return heap_num;
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << s.lengthOfLIS(nums) << std::endl;
    return 0;
}
