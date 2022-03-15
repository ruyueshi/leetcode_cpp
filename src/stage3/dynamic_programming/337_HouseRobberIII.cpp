/**
 * 337. House Robber III
 * Source: https://leetcode-cn.com/problems/house-robber-iii/
 */

#include <iostream>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 动态规划
class SolutionV1 {
public:
    int rob(TreeNode *root) {
        if (!root)
            return 0;
        if (hashtable.find(root) != hashtable.end())
            return hashtable[root];
        int do_rob = root->val + (root->left ? rob(root->left->left) + rob(root->left->right) : 0)
                + (root->right ? rob(root->right->left) + rob(root->right->right) : 0);
        int not_rob = rob(root->left) + rob(root->right);
        int res = std::max(do_rob, not_rob);
        hashtable.insert({root, res});
        return res;
    }

private:
    std::unordered_map<TreeNode*, int> hashtable;
};

// 优化V1
// 压缩空间
class SolutionV2 {
public:
    int rob(TreeNode *root) {
        auto res = traverse(root);  // {抢，不抢}
        return std::max(res.first, res.second);
    }

    std::pair<int, int> traverse(TreeNode *root) {
        if (!root)
            return {0, 0};
        auto left = traverse(root->left), right = traverse(root->right);
        int do_rob = root->val + left.second + right.second;
        int not_rob = std::max(left.first, left.second) + std::max(right.first, right.second);
        return {do_rob, not_rob};
    }
};

int main() {
    SolutionV2 s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    std::cout << s.rob(root) << std::endl;
    root->left->val = 4;
    root->right->val = 5;
    root->left->left = new TreeNode(1);
    root->left->right->val = 3;
    root->right->right->val = 1;
    std::cout << s.rob(root) << std::endl;
    return 0;
}
