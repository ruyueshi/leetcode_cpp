/**
 * 323. Number Of Connected Components In An Undirected Graph
 * Source: https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/
 */

#include <algorithm>
#include <iostream>
#include <vector>

class UF {
public:
    UF(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void union_ij(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);
        if (root_i == root_j)
            return;
        parent[root_i] = root_j;
        count--;
    }

    int get_count() {
        return count;
    }

    bool connected(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);
        return root_i == root_j;
    }

    int find_root(int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

private:
    int count = 0;
    std::vector<int> parent;
};

class Solution {
public:
    int countComponents(int n, std::vector<std::vector<int>> edges) {
        UF uf(n);
        for (auto &e: edges)
            uf.union_ij(e[0], e[1]);
        return uf.get_count();
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> edges = {{0,5},{1,2},{1,3},{3,4}};
    std::cout << s.countComponents(6, edges) << std::endl;
    return 0;
}
