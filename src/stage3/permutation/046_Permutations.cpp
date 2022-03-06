/**
 * 46. Permutations
 * Source: https://leetcode-cn.com/problems/coin-change/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class SolutionV1 {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<int> path;
        backtrack(nums, path);
        return this->res;
    }

private:
    std::vector<std::vector<int>> res;

    void backtrack(const std::vector<int> &nums, std::vector<int> &path) {
        if (path.size() == nums.size()) {
            this->res.push_back(path);
            return;
        }
        for (const auto &i: nums) {
            if (std::find(path.begin(), path.end(), i) == path.end()) {
                path.push_back(i);
                backtrack(nums, path);
                path.pop_back();
            }
        }
    }
};

// V1_2：优化V1，空间换时间
class SolutionV1_2 {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<int> path;
        std::vector<bool> visited(nums.size(), false);
        backtrack(nums, path, visited);
        return this->res;
    }

private:
    std::vector<std::vector<int>> res;

    void backtrack(const std::vector<int> &nums, std::vector<int> &path, std::vector<bool> &visited) {
        if (path.size() == nums.size()) {
            this->res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};

class SolutionV2 {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }

private:
    void backtrack(std::vector<std::vector<int>> &res, std::vector<int> &nums, int first, int len) {
        if (first == len) {
            res.push_back(nums);
            return;
        }
        for (int i = first; i < len; i++) {
            std::swap(nums[i], nums[first]);
            backtrack(res, nums, first + 1, len);
            std::swap(nums[i], nums[first]);
        }
    }
};

int main() {
    SolutionV1_2 s;
    std::vector<int> nums = {1, 2, 3};
    auto res = s.permute(nums);
    for (const auto &v: res)
        print_vector(v);
    return 0;
}