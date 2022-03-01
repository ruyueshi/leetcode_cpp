/**
 * 104. Maximum Depth of Binary Tree
 * Source: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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

class SolutionV1 {
public:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        return std::max(left_max, right_max) + 1;
    }
};

class SolutionV2 {
public:
    int maxDepth(TreeNode *root) {
        int depth = 0;
        backtrack(root, depth);
        return this->res;
    }

private:
    int res = 0;

    void backtrack(TreeNode *root, int &depth) {
        if (!root) {
            res = std::max(res, depth);
            return;
        }
        depth++;
        backtrack(root->left, depth);
        backtrack(root->right, depth);
        depth--;
    }
};

int main() {
    SolutionV2 s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << s.maxDepth(root) << std::endl;
    return 0;
}