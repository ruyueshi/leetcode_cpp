/**
 * 114. Flatten Binary Tree to Linked List
 * Source: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
 */

#include "src/utils/tree.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        auto left = root->left;
        auto right = root->right;
        root->right = left;
        root->left = nullptr;
        auto p = root;
        while (p->right) {
            p = p->right;
        }
        p->right = right;
    }
};

int main() {
    Solution s;
    auto root = construct_tree({1, 2, 5, 3, 4, INT_MIN, 6});
    s.flatten(root);
    print_tree1(root);
    root = construct_tree({0});
    s.flatten(root);
    print_tree1(root);
    return 0;
}
