/**
 * 1254. Number of Closed Islands
 * Source: https://leetcode-cn.com/problems/number-of-closed-islands/
 */

#include <iostream>
#include <vector>

// 添加标志位
class SolutionV1 {
public:
    int closedIsland(std::vector<std::vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        num = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    is_edge_island = false;
                    dfs(grid, i, j);
                    if (!is_edge_island)
                        num++;
                }
            }
        }
        return num;
    }

private:
    size_t m, n;
    int num;
    bool is_edge_island;

    void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1)
            return;
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
            is_edge_island = true;
        grid[i][j] = 1;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

// 别人的方法，在时间和空间上，V2和V1差不多
class SolutionV2 {
public:
    // 主函数：计算封闭岛屿的数量
    int closedIsland(std::vector<std::vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int j = 0; j < n; j++) {
            // 把靠上边的岛屿淹掉
            dfs(grid, 0, j);
            // 把靠下边的岛屿淹掉
            dfs(grid, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            // 把靠左边的岛屿淹掉
            dfs(grid, i, 0);
            // 把靠右边的岛屿淹掉
            dfs(grid, i, n - 1);
        }
        // 遍历 grid，剩下的岛屿都是封闭岛屿
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    // 从 (i, j) 开始，将与之相邻的陆地都变成海水
    void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (grid[i][j] == 1) {
            // 已经是海水了
            return;
        }
        // 将 (i, j) 变成海水
        grid[i][j] = 1;
        // 淹没上下左右的陆地
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                                          {1, 0, 0, 0, 0, 1, 1, 0},
                                          {1, 0, 1, 0, 1, 1, 1, 0},
                                          {1, 0, 0, 0, 0, 1, 0, 1},
                                          {1, 1, 1, 1, 1, 1, 1, 0}};
    std::cout << s.closedIsland(grid) << std::endl;
    grid = {{0, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0}};
    std::cout << s.closedIsland(grid) << std::endl;
    grid = {{1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1}};
    std::cout << s.closedIsland(grid) << std::endl;
    return 0;
}
