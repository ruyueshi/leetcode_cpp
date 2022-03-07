/**
 * 216. Combination Sum III
 * Source: https://leetcode-cn.com/problems/combination-sum-iii/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        int sum = 0;
        traceback(k, n, 1, res, path, sum);
        return res;
    }

private:
    void traceback(int k, int n, int start, std::vector<std::vector<int>> &res, std::vector<int> &path, int &sum) {
        if (path.size() == k && sum == n) {
            res.emplace_back(path);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > (n - sum))
                break;
            sum += i;
            path.emplace_back(i);
            traceback(k, n, i + 1, res, path, sum);
            path.pop_back();
            sum -= i;
        }
    }
};

int main() {
    Solution s;
    auto res = s.combinationSum3(3, 7);
    for (const auto &v: res)
        print_vector(v);
    std::cout << "size: " << res.size() << std::endl;
    res = s.combinationSum3(3, 9);
    for (const auto &v: res)
        print_vector(v);
    std::cout << "size: " << res.size() << std::endl;
    res = s.combinationSum3(4, 1);
    for (const auto &v: res)
        print_vector(v);
    std::cout << "size: " << res.size() << std::endl;
    return 0;
}
