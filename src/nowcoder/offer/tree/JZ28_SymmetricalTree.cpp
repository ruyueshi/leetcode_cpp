#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        return pRoot && isSymmetrical(pRoot->left, pRoot->right);
    }

private:
    bool isSymmetrical(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        } else if (!left || !right) {
            return false;
        } else {
            return left->val == right->val && isSymmetrical(left->left, right->right) &&
                   isSymmetrical(left->right, right->left);
        }
    }
};
