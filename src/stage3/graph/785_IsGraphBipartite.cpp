/**
 * 785. Is Graph Bipartite?
 * Source: https://leetcode-cn.com/problems/is-graph-bipartite/
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>> &graph) {
        int n = graph.size();
        std::vector<bool> color(n, false), visited(n, false);

        for (int s = 0; s < n; s++) {
            if (!visited[s])
                traceback(graph, visited, color, s);
        }
        return is_bipartite;
    }

private:
    bool is_bipartite = true;

    void traceback(const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<bool> &color, int s) {
        if (!is_bipartite)
            return;

        visited[s] = true;
        for (int t: graph[s]) {
            if (!visited[t]) {
                color[t] = !color[s];
                traceback(graph, visited, color, t);
            } else {
                if (color[t] == color[s]) {
                    is_bipartite = false;
                    return;
                }
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> prerequisites = {{1, 2, 3},
                                                   {0, 2},
                                                   {0, 1, 3},
                                                   {0, 1}};
    std::cout << s.isBipartite(prerequisites) << std::endl;
    return 0;
}
