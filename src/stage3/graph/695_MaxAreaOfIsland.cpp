/**
 * 695. Max Area of Island
 * Source: https://leetcode-cn.com/problems/max-area-of-island/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        max_area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    max_area = std::max(dfs(grid, i, j), max_area);
                }
            }
        }
        return max_area;
    }

private:
    size_t m, n;
    int max_area;

    int dfs(std::vector<std::vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {{0, 0, 0, 0},
                                          {1, 0, 1, 0},
                                          {0, 1, 1, 0},
                                          {0, 0, 0, 0}};
    std::cout << s.maxAreaOfIsland(grid) << std::endl;
    grid = {{0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}};
    std::cout << s.maxAreaOfIsland(grid) << std::endl;
    grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    std::cout << s.maxAreaOfIsland(grid) << std::endl;
    return 0;
}
