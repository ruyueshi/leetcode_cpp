/**
 * 77. Combinations
 * Source: https://leetcode-cn.com/problems/combinations/
 */

#include <vector>

#include "src/utils/print.h"

class SolutionV1 {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        traceback(res, path, n, k, 1);
        return res;
    }

private:
    void traceback(std::vector<std::vector<int>> &res, std::vector<int> &path, int n, int k, int start) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            traceback(res, path, n, k, i + 1);
            path.pop_back();
        }
    }
};

// V2：在V1的基础上剪枝
class SolutionV2 {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        traceback(res, path, n, k, 1);
        return res;
    }

private:
    void traceback(std::vector<std::vector<int>> &res, std::vector<int> &path, int n, int k, int start) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = start; i <= (n - (k - path.size() - 1)); i++) {  // 剪枝
            path.push_back(i);
            traceback(res, path, n, k, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    SolutionV2 s;
    auto res = s.combine(4, 2);
    for (const auto &v: res) {
        print_vector(v);
    }
    return 0;
}
