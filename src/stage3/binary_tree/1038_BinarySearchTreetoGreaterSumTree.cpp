/**
 * 1038. Binary Search Tree to Greater Sum Tree
 * Source: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
 */

#include "src/utils/tree.h"

class Solution {
public:
    TreeNode *bstToGst(TreeNode *root) {
        if (!root)
            return nullptr;
        bstToGst(root->right);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left);
        return root;
    }

private:
    int sum = 0;
};

int main() {
    print_tree1(Solution().bstToGst(construct_tree({4, 1, 6, 0, 2, 5, 7, INT_MIN, INT_MIN, INT_MIN, 3, INT_MIN, INT_MIN, INT_MIN, 8})));
    print_tree1(Solution().bstToGst(construct_tree({0, INT_MIN, 1})));
    return 0;
}
