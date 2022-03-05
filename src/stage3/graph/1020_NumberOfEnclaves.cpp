/**
 * 1020. Number of Enclaves
 * Source: https://leetcode-cn.com/problems/number-of-enclaves/
 */

#include <iostream>
#include <vector>

class SolutionV1 {
public:
    int numEnclaves(std::vector<std::vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    is_edge_island = false;
                    single_island_size = 0;
                    dfs(grid, i, j);
                    if (!is_edge_island)
                        num += single_island_size;
                }
            }
        }
        return num;
    }

private:
    size_t m, n;
    int num, single_island_size;
    bool is_edge_island;

    void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
            is_edge_island = true;
        single_island_size++;
        grid[i][j] = 0;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};


// V2：先去掉边界岛屿
// 速度更快
class SolutionV2 {
public:
    int numEnclaves(std::vector<std::vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        // 去掉在左右边界的岛屿
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        // 去掉在上下边界的岛屿
        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    num++;
            }
        }
        return num;
    }

private:
    size_t m, n;
    int num;

    void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<int>> grid = {{0, 0, 0, 0},
                                          {1, 0, 1, 0},
                                          {0, 1, 1, 0},
                                          {0, 0, 0, 0}};
    std::cout << s.numEnclaves(grid) << std::endl;
    grid = {{0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}};
    std::cout << s.numEnclaves(grid) << std::endl;
    return 0;
}
