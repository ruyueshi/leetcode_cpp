/**
 * offer 32-1. 从上到下打印二叉树 III
 * Source: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 */

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;
        std::stack<std::pair<int, TreeNode *>> s1;  // {层数，节点指针} 存放奇数层节点
        std::stack<std::pair<int, TreeNode *>> s2;  // {层数，节点指针} 存放偶数层节点
        if (root)
            s1.push({1, root});  // 第一层
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                auto pa = s1.top();
                s1.pop();
                if (pa.first > res.size())
                    res.push_back({pa.second->val});
                else
                    res[pa.first - 1].push_back(pa.second->val);
                if (pa.second->left)
                    s2.push({pa.first + 1, pa.second->left});
                if (pa.second->right)
                    s2.push({pa.first + 1, pa.second->right});
            }
            while (!s2.empty()) {
                auto pa = s2.top();
                s2.pop();
                if (pa.first > res.size())
                    res.push_back({pa.second->val});
                else
                    res[pa.first - 1].push_back(pa.second->val);
                if (pa.second->right)
                    s1.push({pa.first + 1, pa.second->right});
                if (pa.second->left)
                    s1.push({pa.first + 1, pa.second->left});
            }
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
