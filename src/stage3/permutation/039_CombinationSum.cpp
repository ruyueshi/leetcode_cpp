/**
 * 39. Combination Sum
 * Source: https://leetcode-cn.com/problems/combination-sum/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

// V1：排序+回溯剪枝
class SolutionV1 {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
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
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            traceback(candidates, target, i, res, path, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }
};

// V2：回溯剪枝
class SolutionV2 {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        int sum = 0;
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
                continue;
            sum += candidates[i];
            path.emplace_back(candidates[i]);
            traceback(candidates, target, i, res, path, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> nums = {2, 3, 6, 7};
    auto res = s.combinationSum(nums, 7);
    for (const auto &v: res) {
        print_vector(v);
    }
    std::cout << "size: " << res.size() << std::endl;
    nums = {2, 3, 5};
    res = s.combinationSum(nums, 8);
    for (const auto &v: res) {
        print_vector(v);
    }
    std::cout << "size: " << res.size() << std::endl;
    return 0;
}
