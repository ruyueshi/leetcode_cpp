/**
 * 111. Minimum Depth of Binary Tree
 * Source: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 */

#include <iostream>
#include <queue>

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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *temp = q.front();
                q.pop();
                if (!temp->left && !temp->right)
                    return step;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            step++;
        }
        return step;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << s.minDepth(root) << std::endl;
    return 0;
}
