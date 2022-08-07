/**
 * JZ79. 判断是不是平衡二叉树
 * Source: https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=23250&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"

using namespace std;

class Solution {
public:
    bool IsBalanced_Solution(TreeNode *pRoot) {
        return is_balanced_tree(pRoot);
    }

private:
    bool is_balanced_tree(TreeNode *root) {
        if (!root) { return true; }
        return is_balanced_tree(root->left) && is_balanced_tree(root->right) &&
               std::abs(deepth(root->left) - deepth(root->right)) <= 1;
    }

    int deepth(TreeNode *root) {
        if (!root) { return 0; }
        return std::max(deepth(root->left), deepth(root->right)) + 1;
    }
};

int main() {
    Solution s;
    std::cout << s.IsBalanced_Solution(construct_tree({1, 2, 3, 4, 5, 6, 7})) << std::endl;
    return 0;
}
