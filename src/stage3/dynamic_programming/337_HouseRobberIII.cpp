/**
 * 337. House Robber III
 * Source: https://leetcode-cn.com/problems/house-robber-iii/
 */

#include <iostream>
#include <map>

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
    int rob(TreeNode *root) {
        return std::max(traverse(root, true), traverse(root, false));
    }

    int traverse(TreeNode *root, bool rob) {
        if (!root)
            return 0;
        if (rob) {
            // 当前节点偷，则其子节点不可以偷
            int left_false, right_false;
            if (m.find({root->left, false}) != m.end()) {
                left_false = m[{root->left, false}];
            } else {
                left_false = traverse(root->left, false);
                m.insert({{root->left, false}, left_false});
            }
            if (m.find({root->right, false}) != m.end()) {
                right_false = m[{root->right, false}];
            } else {
                right_false = traverse(root->right, false);
                m.insert({{root->right, false}, right_false});
            }
            return root->val + left_false + right_false;
        }
        else {
            // 当前节点不偷，则其子节点可以偷也可以不偷
            int left_max = std::max(traverse(root->left, true), traverse(root->left, false));
            int right_max = std::max(traverse(root->right, true), traverse(root->right, false));
            return left_max + right_max;
        }
    }

private:
    std::map<std::pair<TreeNode*, bool>, int> m;
};

int main() {
    Solution s;
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
