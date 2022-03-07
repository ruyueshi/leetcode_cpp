/**
 * 46. Permutations
 * Source: https://leetcode-cn.com/problems/coin-change/
 */

#include <algorithm>
#include <unordered_set>
#include <vector>

#include "src/utils/print.h"

// V1：使用集合来去重
class SolutionV1 {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::vector<int> path;
        std::vector<bool> visited(nums.size(), false);
        traceback(nums, path, visited);
        return res;
    }

private:
    std::vector<std::vector<int>> res;

    void traceback(const std::vector<int> &nums, std::vector<int> &path, std::vector<bool> &visited) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        std::unordered_set<int> temp_set;  // 使用集合去除重复
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || temp_set.find(nums[i]) != temp_set.end())
                continue;
            temp_set.insert(nums[i]);
            visited[i] = true;
            path.emplace_back(nums[i]);
            traceback(nums, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};

// V2：先排序再回溯
class SolutionV2 {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::vector<int> path;
        std::vector<bool> visited(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        traceback(nums, path, visited);
        return res;
    }

private:
    std::vector<std::vector<int>> res;

    void traceback(const std::vector<int> &nums, std::vector<int> &path, std::vector<bool> &visited) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])  // 注意体会此处细节：!visited[i - 1]
                continue;
            visited[i] = true;
            path.emplace_back(nums[i]);
            traceback(nums, path, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> nums = {1, 2, 1};
    auto res = s.permuteUnique(nums);
    for (const auto &v: res)
        print_vector(v);
    return 0;
}
