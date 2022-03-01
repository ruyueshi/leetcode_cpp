/**
 * 543. Diameter of Binary Tree
 * Source: https://leetcode-cn.com/problems/diameter-of-binary-tree/
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        maxDepth(root);
        return this->diameter;
    }

    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);
        this->diameter = std::max(this->diameter, left_max_depth + right_max_depth);
        return std::max(left_max_depth, right_max_depth) + 1;
    }

private:
    int diameter = 0;
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    std::cout << s.diameterOfBinaryTree(root) << std::endl;
    return 0;
}
