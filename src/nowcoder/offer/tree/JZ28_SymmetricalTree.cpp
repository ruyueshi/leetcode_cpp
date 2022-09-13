/**
 * JZ28 对称的二叉树
 * Source: https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=23452&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

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
