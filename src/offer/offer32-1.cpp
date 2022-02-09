/**
 * offer 32-1. 从上到下打印二叉树 I
 * Source: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
 */

#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> levelOrder(TreeNode* root) {
        std::vector<int> res;
        std::queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            res.push_back(p->val);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        return res;
    }
};

int main() {
    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    auto p = root->right;
    p->left = new TreeNode(15);
    p->right = new TreeNode(7);
    std::vector<int> res = Solution().levelOrder(root);
    for (auto &i: res)
        std::cout << i << ",";
    std::cout << std::endl;
    return 0;
}
