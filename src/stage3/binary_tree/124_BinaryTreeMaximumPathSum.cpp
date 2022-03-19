/**
 * 124. Binary Tree Maximum Path Sum
 * Source: https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 */

#include <algorithm>
#include "src/utils/tree.h"

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        res = INT_MIN;
        traceback(root);
        return res;
    }

private:
    int res;

    int traceback(TreeNode *root) {
        if (!root)
            return 0;
        int left_max = traceback(root->left);
        int right_max = traceback(root->right);
        int max_root = std::max({root->val, left_max + root->val, right_max + root->val});
        res = std::max({res, max_root, left_max + right_max + root->val});
        return max_root;
    }
};

int main() {
    Solution s;
    std::cout << s.maxPathSum(construct_tree({1, -2, -3, 1, 3, -2, INT_MIN, -1})) << std::endl;
    std::cout << s.maxPathSum(construct_tree({-10, 9, 20, INT_MIN, INT_MIN, 15, 7})) << std::endl;
    std::cout << s.maxPathSum(construct_tree({2, -1, -2})) << std::endl;
    std::cout << s.maxPathSum(construct_tree({-3})) << std::endl;
    std::cout << s.maxPathSum(construct_tree({5, 4, 8, 11, INT_MIN, 13, 4, 7, 2, INT_MIN, INT_MIN, INT_MIN, 1})) << std::endl;
    return 0;
}
