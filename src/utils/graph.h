#ifndef LEETCODE_CPP_GRAPH_H
#define LEETCODE_CPP_GRAPH_H

#include <vector>

// 并查集
class UF {
public:
    UF(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    void uf_union(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);
        if (root_i == root_j)
            return;
        parent[root_i] = root_j;
        count--;
    }

    bool uf_connect(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);
        return root_i == root_j;
    }

    int uf_count() {
        return count;
    }

private:
    int count;
    std::vector<int> parent;

    int find_root(int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
};

#endif //LEETCODE_CPP_GRAPH_H
