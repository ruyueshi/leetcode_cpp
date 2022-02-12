/**
 * offer 28. 对称的二叉树
 * Source: https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 */

#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return false;
        return this->isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        else if (t1 == nullptr || t2 == nullptr)
            return false;
        else
            return t1->val == t2->val && isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    std::cout << Solution().isSymmetric(root) << std::endl;
    return 0;
}
