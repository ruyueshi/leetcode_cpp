/**
 * 144. Binary Tree Preorder Traversal
 * Source: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */

#include <vector>

#include "src/utils/print.h"

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
    std::vector<int> preorderTraversal(TreeNode *root) {
        traversal(root);
        return this->res;
    }

    void traversal(TreeNode *root) {
        if (!root)
            return;
        res.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }

private:
    std::vector<int> res;
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    auto res = s.preorderTraversal(root);
    print_vector(res);
    return 0;
}

