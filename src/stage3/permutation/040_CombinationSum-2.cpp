/**
 * 90. Subsets II
 * Source: https://leetcode-cn.com/problems/subsets-ii/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        int sum = 0;
        std::sort(candidates.begin(), candidates.end());
        traceback(candidates, target, 0, res, path, sum);
        return res;
    }

private:
    void traceback(const std::vector<int> &candidates, int target, int start, std::vector<std::vector<int>> &res, std::vector<int> &path, int &sum) {
        if (sum == target) {
            res.emplace_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > (target - sum))
                break;
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            traceback(candidates, target, i + 1, res, path, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    auto res = s.combinationSum2(nums, 8);
    for (const auto &v: res) {
        print_vector(v);
    }
    std::cout << "size: " << res.size() << std::endl;
    nums = {2, 5, 2, 1, 2};
    res = s.combinationSum2(nums, 5);
    for (const auto &v: res) {
        print_vector(v);
    }
    std::cout << "size: " << res.size() << std::endl;
    return 0;
}

