/**
 * 18. 4Sum
 * Source: https://leetcode-cn.com/problems/4sum/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class SolutionV1 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &&nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])  // 去重
                continue;
            threeSum(nums, i + 1, target - nums[i], res);
        }
        return res;
    }

private:
    void threeSum(const std::vector<int> &nums, int start, int target, std::vector<std::vector<int>> &res) {
        int n = nums.size();
        for (int i = start; i < n - 2; i++) {
            if (i > start && nums[i] == nums[i - 1])  // 去重
                continue;
            int twosum_target = target - nums[i];
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[low] + nums[high];
                int left_value = nums[low], right_value = nums[high];
                if (sum < twosum_target) {
                    while (low < high && nums[low] == left_value)
                        low++;
                } else if (sum > twosum_target) {
                    while (low < high && nums[high] == right_value)
                        high--;
                } else {
                    res.push_back({nums[start - 1], nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == left_value)
                        low++;
                    while (low < high && nums[high] == right_value)
                        high--;
                }
            }
        }
    }
};

// 优化V1
// 非递归
class SolutionV2 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &&nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])  // 去重
                continue;
            int start = i + 1, threesum_target = target - nums[i];
            for (int j = i + 1; j < n - 2; j++) {
                if (j > start && nums[j] == nums[j - 1])  // 去重
                    continue;
                int twosum_target = threesum_target - nums[j];
                int low = j + 1, high = n - 1;
                while (low < high) {
                    int sum = nums[low] + nums[high];
                    int left_value = nums[low], right_value = nums[high];
                    if (sum < twosum_target) {
                        while (low < high && nums[low] == left_value)
                            low++;
                    } else if (sum > twosum_target) {
                        while (low < high && nums[high] == right_value)
                            high--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[low] == left_value)
                            low++;
                        while (low < high && nums[high] == right_value)
                            high--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    SolutionV2 s;
    auto res = s.fourSum({1, 0, -1, 0, -2, 2}, 0);
    for (auto &v: res) {
        print_vector(v);
    }
    res = s.fourSum({2, 2, 2, 2, 2}, 8);
    for (auto &v: res) {
        print_vector(v);
    }
    return 0;
}
