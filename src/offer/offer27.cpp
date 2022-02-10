/**
 * offer 27. 二叉树的镜像
 * Source: https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
 */

#include <iostream>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 使用栈进行深度优先搜索
class SolutionV1 {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        std::stack<TreeNode *> s;
        if (root)
            s.push(root);
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            if (p->left)
                s.push(p->left);
            if (p->right)
                s.push(p->right);
            std::swap(p->left, p->right);
        }
        return root;
    }
};

// 递归
class SolutionV2 {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (!root)
            return nullptr;
        TreeNode *temp = root->left;
        root->left = this->mirrorTree(root->right);
        root->right = this->mirrorTree(temp);
        return root;
    }
};

int main() {
    auto root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    auto res = SolutionV2().mirrorTree(root);
    std::queue<TreeNode *> q;
    if (res)
        q.push(res);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        std::cout << p->val << ",";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    std::cout << std::endl;
    return 0;
}
