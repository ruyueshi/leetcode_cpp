/**
 * 797. All Paths From Source to Target
 * Source: https://leetcode-cn.com/problems/all-paths-from-source-to-target/
 */

#include <iostream>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(const std::vector<std::vector<int>> &graph) {
        n = graph.size();
        std::vector<int> path = {0};
        traceback(graph, path, 0);
        return res;
    }

private:
    int n;
    std::vector<std::vector<int>> res;

    void traceback(const std::vector<std::vector<int>> &graph, std::vector<int> &path, int i) {
        if (i == n - 1) {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < graph[i].size(); j++) {
            path.push_back(graph[i][j]);
            traceback(graph, path, graph[i][j]);
            path.pop_back();
        }
    }
};

int main() {
    auto res = Solution().allPathsSourceTarget({{1, 2},
                                                {3},
                                                {3},
                                                {}});
    for (auto &v: res)
        print_vector(v);
    return 0;
}
