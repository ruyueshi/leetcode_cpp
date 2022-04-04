/**
 * 528. 按权重随机选择
 * Source: https://leetcode-cn.com/problems/random-pick-with-weight/
 */

#include <bits/stdc++.h>
#include <ctime>
#include <iostream>
#include <vector>

class Solution {
public:
    Solution(std::vector<int> &w) {
        srand((unsigned) time(NULL));
        n = w.size();
        pre_sum.resize(n + 1);
        pre_sum[0] = 0;
        for (int i = 0; i < n; i++)
            pre_sum[i + 1] = pre_sum[i] + w[i];
    }

    int pickIndex() {
        int rand_val = rand() % pre_sum[n] + 1;  // 在[1, pre_sum[n]]之间随机选择一个数字
        return binary_left_bound(pre_sum, rand_val) - 1;
    }

private:
    std::vector<int> pre_sum;
    int n;

    int binary_left_bound(std::vector<int> &nums, int target) {
        if (nums.size() == 0)
            return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    std::vector<int> w = {1, 3};
    Solution s(w);
    std::cout << s.pickIndex() << std::endl;
    return 0;
}
