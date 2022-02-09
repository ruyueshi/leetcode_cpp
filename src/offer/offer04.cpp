/**
 * offer 04. 二维数组中的查找
 * Source: https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 */

#include <iostream>
#include <stack>
#include <vector>

// 使用深度优先搜索
// 16ms, 12.9MB
class SolutionV1 {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target) {
        std::stack<std::pair<int, int>> s;
        size_t m = matrix.size();
        size_t n = m > 0 ? matrix[0].size() : 0;
        size_t i = 0, j = 0;
        std::vector<std::vector<bool>> visit(m, std::vector<bool>(n));  // 默认初始化为false
        while (i < m && j < n) {
            if (matrix[i][j] == target)
                return true;
            visit[i][j] = true;
            int down = -1, right = -1;
            if (i + 1 < m && !visit[i + 1][j] && matrix[i + 1][j] <= target)
                down = matrix[i + 1][j] - matrix[i][j];
            if (j + 1 < n && !visit[i][j + 1] && matrix[i][j + 1] <= target)
                right = matrix[i][j + 1] - matrix[i][j];
            if (down == -1 && right == -1) {
                if (i + 1 < m)
                    visit[i + 1][j] = true;
                if (j + 1 < n)
                    visit[i][j + 1] = true;
                if (s.empty())
                    return false;
                auto pa = s.top();
                s.pop();
                i = pa.first, j = pa.second;
                continue;
            } else {
                if (down <= right) {
                    if (down > -1)
                        s.push({i + 1, j});
                    else if (i + 1 < m)
                        visit[i + 1][j] = true;
                    // 往右走
                    j += 1;
                } else {
                    if (right > -1)
                        s.push({i, j + 1});
                    else if (j + 1 < n)
                        visit[i][j + 1] = true;
                    // 往下走
                    i += 1;
                }
            }
        }
        return false;
    }
};

// 使用二叉搜索树
// 16ms, 12.6MB
class SolutionV2 {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (target < matrix[i][j])
                i--;
            else if (target > matrix[i][j])
                j++;
            else
                return true;
        }
        return false;
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<int>> m = {{1,  4,  7,  11, 15},
                                       {2,  5,  8,  12, 19},
                                       {3,  6,  9,  16, 22},
                                       {10, 13, 14, 17, 24},
                                       {18, 21, 23, 26, 30}};
    std::cout << s.findNumberIn2DArray(m, 0) << std::endl;
    return 0;
}
