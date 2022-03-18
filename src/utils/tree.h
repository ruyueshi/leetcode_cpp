#ifndef LEETCODE_CPP_TREE_H
#define LEETCODE_CPP_TREE_H

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * nodes = {3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1}; // INT_MIN means null node;
 */
static TreeNode *construct_tree(std::vector<int> nodes) {
    if (nodes.size() == 0)
        return nullptr;
    auto root = new TreeNode(nodes[0]), p = root;
    std::queue<TreeNode *> q;
    for (int i = 1; i < nodes.size(); i++) {
        if ()
    }
}

#endif //LEETCODE_CPP_TREE_H
