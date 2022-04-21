/**
 * 42. Trapping Rain Water
 * Source: https://leetcode-cn.com/problems/trapping-rain-water/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    // 动态规划，较复杂
    int trap_v1(const std::vector<int> &height) {
        int n = height.size();
        if (n <= 1)
            return 0;
        std::vector<int> dp(n);
        std::vector<int> water(n);
        int max_index = 0, max_h = height[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            if (height[i] > height[i - 1]) {
                if (height[i] >= max_h) {
                    for (int j = max_index + 1; j < i; j++) {
                        int addition = std::max(0, (max_h - height[j]) - water[j]);
                        dp[i] += addition;
                        water[j] += addition;
                    }
                    max_h = height[i];
                    max_index = i;
                } else {
                    int j = i - 1;
                    while (j > max_index && height[j] < height[i]) {
                        int addition = std::max(0, (height[i] - height[j]) - water[j]);
                        dp[i] += addition;
                        water[j] += addition;
                        j--;
                    }
                }
            }
        }
        return dp[n - 1];
    }

    // 双指针
    int trap_v2(const std::vector<int> &height) {
        int n = height.size();
        int max_left = height[0], max_right = height[n - 1];
        int left = 1, right = n - 2;
        int sum = 0;
        while (left <= right) {
            max_left = std::max(max_left, height[left]);  // left左边最大高度
            max_right = std::max(max_right, height[right]);  // right右边最大高度
            if (max_left < max_right) {
                sum += (max_left - height[left]);
                left++;
            } else {
                sum += (max_right - height[right]);
                right--;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.trap_v2({2, 0, 2}) << std::endl;
    std::cout << s.trap_v2({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << std::endl;
    std::cout << s.trap_v2({4, 2, 0, 3, 2, 5}) << std::endl;
    return 0;
}
