/**
 * JZ82. 二叉树中和为某一值的路径（一）
 * Source: https://www.nowcoder.com/practice/508378c0823c423baa723ce448cbfd0c?tpId=13&tqId=634&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"

using namespace std;

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode *root, int sum) {
        // write code here
        if (!root) { return false; }
        return dfs(root, sum, 0);
    }

private:
    bool dfs(const TreeNode *root, const int sum, int path_sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return path_sum + root->val == sum;
        }
        return dfs(root->left, sum, path_sum + root->val) ||
               dfs(root->right, sum, path_sum + root->val);
    }
};

int main() {
    Solution s;
    std::cout << s.hasPathSum(construct_tree({1, 2}), 1) << std::endl;
    std::cout << s.hasPathSum(construct_tree({5, 4, 8, 1, 11, INT_MIN, 9, INT_MIN, INT_MIN, 2, 7}), 22) << std::endl;
    return 0;
}
