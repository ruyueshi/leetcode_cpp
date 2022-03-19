/**
 * 226. Invert Binary Tree
 * Source: https://leetcode-cn.com/problems/invert-binary-tree/
 */

#include "src/utils/tree.h"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root)
            return nullptr;
        auto temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};

int main() {
    Solution s;
    print_tree1(s.invertTree(construct_tree({4, 2, 7, 1, 3, 6, 9})));
    print_tree1(s.invertTree(construct_tree({2, 1, 3})));
    print_tree1(s.invertTree(construct_tree({})));
    return 0;
}
