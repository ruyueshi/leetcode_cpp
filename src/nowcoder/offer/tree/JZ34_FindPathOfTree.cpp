/**
 * JZ34. 二叉树中和为某一值的路径（二）
 * Source: https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=23276&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"
#include "src/utils/print.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        if (!root) { return {}; }
        std::vector<int> path;
        dfs(root, expectNumber, path, 0);
        return res;
    }

private:
    std::vector<std::vector<int>> res;

    void dfs(const TreeNode *root, const int expectNumber, std::vector<int> &path, int path_sum) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right && path_sum + root->val == expectNumber) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        dfs(root->left, expectNumber, path, path_sum + root->val);
        dfs(root->right, expectNumber, path, path_sum + root->val);
        path.pop_back();
    }
};

int main() {
    Solution s;
    auto res = s.FindPath(construct_tree({5, 4, 8, 1, 11, INT_MIN, 9, INT_MIN, INT_MIN, 2, 7}), 22);
    for (const auto &i: res) {
        print_vector(i);
    }
    return 0;
}
