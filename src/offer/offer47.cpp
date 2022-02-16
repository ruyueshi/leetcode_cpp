/**
 * offer 47. 礼物的最大价值
 * Source: https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxValueV1(std::vector<std::vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> F(m, std::vector<int>(n));
        F[0][0] = grid[0][0];
        for (size_t i = 1, j = 0; i < m; i++)
            F[i][j] = F[i - 1][j] + grid[i][j];
        for (size_t j = 1, i = 0; j < n; j++)
            F[i][j] = F[i][j - 1] + grid[i][j];
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                F[i][j] = std::max(F[i - 1][j] + grid[i][j], F[i][j - 1] + grid[i][j]);
            }
        }
        return F[m - 1][n - 1];
    }

    int maxValueV2(std::vector<std::vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (size_t i = 1, j = 0; i < m; i++)
            grid[i][j] = grid[i - 1][j] + grid[i][j];
        for (size_t j = 1, i = 0; j < n; j++)
            grid[i][j] = grid[i][j - 1] + grid[i][j];
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                grid[i][j] = std::max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {{1, 3, 1},
                                          {1, 5, 1},
                                          {4, 2, 1}};
    std::cout << s.maxValueV2(grid) << std::endl;
    return 0;
}
