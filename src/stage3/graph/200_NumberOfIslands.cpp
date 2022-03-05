/**
 * 200. Number of Islands
 * Source: https://leetcode-cn.com/problems/number-of-islands/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        m = grid.size(), n = grid[0].size();
        int num = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    dfs(grid, i, j);
                }
            }
        }
        return num;
    }

private:
    size_t m, n;
    int d[4][2] = {{-1, 0},
                   {1,  0},
                   {0,  -1},
                   {0,  1}};

    void dfs(std::vector<std::vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for (auto &dd: d)
            dfs(grid, i + dd[0], j + dd[1]);
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                           {'1', '1', '0', '1', '0'},
                                           {'1', '1', '0', '0', '0'},
                                           {'0', '0', '0', '0', '0'}};
    std::cout << s.numIslands(grid) << std::endl;
    grid = {{'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};
    std::cout << s.numIslands(grid) << std::endl;
    return 0;
}
