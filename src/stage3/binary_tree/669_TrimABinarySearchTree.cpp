/**
 * 543. Diameter of Binary Tree
 * Source: https://leetcode-cn.com/problems/diameter-of-binary-tree/
 */

#include "src/utils/tree.h"

class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root)
            return nullptr;
        if (root->val < low) {
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            return trimBST(root->left, low, high);
        } else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};

int main() {
    Solution s;
    print_tree1(s.trimBST(construct_tree({1, 0, 2}), 1, 2));
    print_tree1(s.trimBST(construct_tree({3, 0, 4, -1, 2, -1, -1, 1}), 1, 3));
    return 0;
}
