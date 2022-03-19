/**
 * 538. Convert BST to Greater Tree
 * Source: https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 */

#include "src/utils/tree.h"

class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        if (!root)
            return nullptr;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }

private:
    int sum = 0;
};

int main() {
    print_tree1(Solution().convertBST(construct_tree({4, 1, 6, 0, 2, 5, 7, INT_MIN, INT_MIN, INT_MIN, 3, INT_MIN, INT_MIN, INT_MIN, 8})));
    print_tree1(Solution().convertBST(construct_tree({0, INT_MIN, 1})));
    return 0;
}
