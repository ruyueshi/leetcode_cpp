/**
 * offer 32-1. 从上到下打印二叉树 II
 * Source: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        std::queue<std::pair<int, TreeNode*>> q;  // {层数，节点}
        if (root)
            q.push({1, root});  // 第一层
        while (!q.empty()) {
            auto pa = q.front();
            q.pop();
            if (pa.first > res.size())
                res.push_back({pa.second->val});
            else
                res[pa.first - 1].push_back(pa.second->val);
            if (pa.second->left)
                q.push({pa.first + 1, pa.second->left});
            if (pa.second->right)
                q.push({pa.first + 1, pa.second->right});
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
    std::vector<std::vector<int>> res = Solution().levelOrder(root);
    for (auto &i: res) {
        for (auto &j: i)
            std::cout << j << ",";
        std::cout << std::endl;
    }
    return 0;
}
