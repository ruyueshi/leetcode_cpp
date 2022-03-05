/**
 * 1905. Count Sub Islands
 * Source: https://leetcode-cn.com/problems/count-sub-islands/
 */

#include <iostream>
#include <vector>

class SolutionV1 {
public:
    int countSubIslands(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2) {
        m = grid2.size(), n = grid2[0].size();
        num = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    is_sub_island = true;
                    dfs(grid1, grid2, i, j);
                    if (is_sub_island)
                        num++;
                }
            }
        }
        return num;
    }

private:
    size_t m, n;
    int num;
    bool is_sub_island;

    void dfs(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)
            return;
        if (grid1[i][j] == 0)
            is_sub_island = false;
        grid2[i][j] = 0;
        dfs(grid1, grid2, i - 1, j);
        dfs(grid1, grid2, i + 1, j);
        dfs(grid1, grid2, i, j - 1);
        dfs(grid1, grid2, i, j + 1);
    }
};

class SolutionV2 {
public:
    int countSubIslands(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2) {
        m = grid2.size(), n = grid2[0].size();
        num = 0;
        // 先将不可能是子岛屿的岛屿“淹没”掉
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && grid1[i][j] == 0)
                    dfs(grid2, i, j);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    dfs(grid2, i, j);
                    num++;
                }
            }
        }
        return num;
    }

private:
    size_t m, n;
    int num;

    void dfs(std::vector<std::vector<int>> &grid2, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)
            return;
        grid2[i][j] = 0;
        dfs(grid2, i - 1, j);
        dfs(grid2, i + 1, j);
        dfs(grid2, i, j - 1);
        dfs(grid2, i, j + 1);
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<int>> grid1 = {{1, 1, 1, 0, 0},
                                           {0, 1, 1, 1, 1},
                                           {0, 0, 0, 0, 0},
                                           {1, 0, 0, 0, 0},
                                           {1, 1, 0, 1, 1}};
    std::vector<std::vector<int>> grid2 = {{1, 1, 1, 0, 0},
                                           {0, 0, 1, 1, 1},
                                           {0, 1, 0, 0, 0},
                                           {1, 0, 1, 1, 0},
                                           {0, 1, 0, 1, 0}};
    std::cout << s.countSubIslands(grid1, grid2) << std::endl;
    grid1 = {{1, 0, 1, 0, 1},
             {1, 1, 1, 1, 1},
             {0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1},
             {1, 0, 1, 0, 1}};
    grid2 = {{0, 0, 0, 0, 0},
             {1, 1, 1, 1, 1},
             {0, 1, 0, 1, 0},
             {0, 1, 0, 1, 0},
             {1, 0, 0, 0, 1}};
    std::cout << s.countSubIslands(grid1, grid2) << std::endl;
    return 0;
}
