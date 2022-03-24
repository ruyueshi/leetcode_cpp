/**
 * 323. Number Of Connected Components In An Undirected Graph
 * Source: https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/
 */

#include <iostream>
#include <vector>

#include "src/utils/graph.h"

class Solution {
public:
    int countComponents(int n, std::vector<std::vector<int>> edges) {
        UF uf(n);
        for (auto &e: edges)
            uf.uf_union(e[0], e[1]);
        return uf.uf_count();
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> edges = {{0,5},{1,2},{1,3},{3,4}};
    std::cout << s.countComponents(6, edges) << std::endl;
    return 0;
}
