/**
 * 694. Numver of Distinct Islands
 * Source: https://leetcode-cn.com/problems/number-of-distinct-islands/
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>

class SolutionV1 {
public:
    int numDistinctIslands(std::vector<std::vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        std::set<std::set<std::pair<int, int>>> s;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    std::set<std::pair<int, int>> island;
                    dfs(grid, i, j, reinterpret_cast<std::set<std::pair<int, int>> &>(island));
                    s.insert(normalize(reinterpret_cast<const std::set<std::pair<int, int>> &>(island)));
                }
            }
        }
        return s.size();
    }

private:
    size_t m, n;

    void dfs(std::vector<std::vector<int>> &grid, int i, int j, std::set<std::pair<int, int>> &island) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        island.insert({i, j});
        dfs(grid, i - 1, j, island);
        dfs(grid, i + 1, j, island);
        dfs(grid, i, j - 1, island);
        dfs(grid, i, j + 1, island);
    }

    std::set<std::pair<int, int>> normalize(const std::set<std::pair<int, int>> &island) {
        std::set<std::pair<int, int>> res;
        auto x_min_it = std::min_element(island.begin(), island.end(), [](std::pair<int, int> e1, std::pair<int, int> e2){return e1.first < e2.first;});
        auto y_min_it = std::min_element(island.begin(), island.end(), [](std::pair<int, int> e1, std::pair<int, int> e2){return e1.second < e2.second;});
        for (auto it = island.begin(); it != island.end(); ++it) {
            res.insert({it->first - x_min_it->first, it->second - y_min_it->second});
        }
        return res;
    }
};

// 相同的岛屿从同一起点出发，dfs的遍历路径是一样的
class SolutionV2 {
public:
    int numDistinctIslands(std::vector<std::vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        std::unordered_set<std::string> s;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    std::string path;
                    dfs(grid, i, j, path, 0);
                    s.insert(path);
                }
            }
        }
        return s.size();
    }

private:
    size_t m, n;

    void dfs(std::vector<std::vector<int>> &grid, int i, int j, std::string &path, int dir) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        path.push_back('0' + dir);
        dfs(grid, i - 1, j, path, 1);
        dfs(grid, i + 1, j, path, 2);
        dfs(grid, i, j - 1, path, 3);
        dfs(grid, i, j + 1, path, 4);
        path.push_back('5' + dir);
    }

    std::set<std::pair<int, int>> normalize(const std::set<std::pair<int, int>> &island) {
        std::set<std::pair<int, int>> res;
        auto x_min_it = std::min_element(island.begin(), island.end(), [](std::pair<int, int> e1, std::pair<int, int> e2){return e1.first < e2.first;});
        auto y_min_it = std::min_element(island.begin(), island.end(), [](std::pair<int, int> e1, std::pair<int, int> e2){return e1.second < e2.second;});
        for (auto it = island.begin(); it != island.end(); ++it) {
            res.insert({it->first - x_min_it->first, it->second - y_min_it->second});
        }
        return res;
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<int>> grid = {{0, 0, 0, 0},
                                          {1, 0, 1, 0},
                                          {0, 1, 1, 0},
                                          {0, 0, 0, 0}};
    std::cout << s.numDistinctIslands(grid) << std::endl;
    grid = {{0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}};
    std::cout << s.numDistinctIslands(grid) << std::endl;
    grid = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}};
    std::cout << s.numDistinctIslands(grid) << std::endl;
    return 0;
}