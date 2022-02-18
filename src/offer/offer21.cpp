/**
 * offer 21. 调整数组顺序使奇数位于偶数前面
 * Source: https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    // 双指针
    std::vector<int> exchangeV1(std::vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] % 2 == 0 && nums[j] % 2 == 1) {
                std::swap(nums[i], nums[j]);
                i++, j--;
            } else if (nums[i] % 2 == 0) {
                j--;
            } else if (nums[j] % 2 == 1) {
                i++;
            } else {
                i++, j--;
            }
        }
        return nums;
    }

    // 优化V1
    std::vector<int> exchangeV2(std::vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] % 2 == 1)
                i++;
            else if (nums[j] % 2 == 0)
                j--;
            else {
                std::swap(nums[i], nums[j]);
                i++, j--;
            }
        }
        return nums;
    }

    // 优雅写法
    std::vector<int> exchangeV3(std::vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] % 2 == 1) i++;
            while (i < j && nums[j] % 2 == 0) j--;
            if (i < j) std::swap(nums[i], nums[j]);
        }
        return nums;
    }
};


int main() {
    Solution s;
    std::vector<int> v = {11, 9, 3, 7, 16, 4, 2, 0};
    auto res = s.exchangeV2(v);
    for (auto &i: res) {
        std::cout << i << ",";
    }
    std::cout << "\b\n";
    return 0;
}
