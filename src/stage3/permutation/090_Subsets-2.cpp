/**
 * 90. Subsets II
 * Source: https://leetcode-cn.com/problems/subsets-ii/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        std::sort(nums.begin(), nums.end());
        traceback(nums, 0, res, path);
        return res;
    }

private:
    void traceback(const std::vector<int> &nums, int start, std::vector<std::vector<int>> &res, std::vector<int> &path) {
        res.emplace_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.emplace_back(nums[i]);
            traceback(nums, i + 1, res, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 2, 2, 5};
    auto res = s.subsetsWithDup(nums);
    for (const auto &v: res) {
        print_vector(v);
    }
    std::cout << "size: " << res.size() << std::endl;
    nums = {4, 4, 4, 1, 4};
    res = s.subsetsWithDup(nums);
    for (const auto &v: res) {
        print_vector(v);
    }
    std::cout << "size: " << res.size() << std::endl;
    return 0;
}

