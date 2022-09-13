/**
 * JZ68 二叉搜索树的最近公共祖先
 * Source: https://www.nowcoder.com/practice/d9820119321945f588ed6a26f0a6991f?tpId=13&tqId=2290592&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (p > q) {
            std::swap(p, q);
        }
        return traceback(root, p, q);
    }

private:
    int traceback(TreeNode* root, int p, int q) {
        if (q < root->val) {
            return traceback(root->left, p, q);
        } else if (p > root->val) {
            return traceback(root->right, p, q);
        } else {
            return root->val;
        }
    }
};
