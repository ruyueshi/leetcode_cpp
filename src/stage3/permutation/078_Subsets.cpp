/**
 * 78. Subsets
 * Source: https://leetcode-cn.com/problems/subsets/
 */

#include <vector>

#include "src/utils/print.h"

// V1: 深度优先搜索
// 耗时0ms，击败率100%
class SolutionV1 {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        for (int sub_size = 0; sub_size <= nums.size(); sub_size++) {
            std::vector<int> subset;
            dfs(nums, subset, sub_size, 0);
        }
        return res;
    }

private:
    std::vector<std::vector<int>> res;

    void dfs(const std::vector<int> &nums, std::vector<int> &subset, int sub_size, int index) {
        if (subset.size() == sub_size) {
            res.push_back(subset);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(nums, subset, sub_size, i + 1);
            subset.pop_back();
        }
    }
};

// V2: 回溯
// 优化V1
class SolutionV2 {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        traceback(nums, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;

    void traceback(const std::vector<int> &nums, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            traceback(nums, i + 1);
            path.pop_back();
        }
    }
};

// 如果要统计子集数量，可以考虑使用动态规划
class SolutionV3 {
public:
    int subsets(std::vector<int> &nums) {
        size_t len = nums.size();
        std::vector<std::vector<int>> dp(len + 1, std::vector<int>(len + 1, 0));
        for (int i = 1; i <= len; i++) {
            dp[i][1] = i;
            dp[i][i] = 1;
            for (int j = 2; j < i; j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }

        int res = 1;  // {}空集也算子集
        for (int j = 1; j <= len; j++) {
            res += dp[len][j];
        }
        return res;
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> nums = {1, 2, 3, 5};
    auto res = s.subsets(nums);
    for (const auto &v: res) {
        print_vector(v);
    }
    std::cout << res.size() << ",";
    std::cout << SolutionV3().subsets(nums) << std::endl;
    return 0;
}
