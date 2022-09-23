/**
 * JZ84. 二叉树中和为某一值的路径（三）
 * Source: https://www.nowcoder.com/practice/965fef32cae14a17a8e86c76ffe3131f?tpId=13&tqId=2277604&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型
     */
    int FindPath(TreeNode *root, int sum) {
        // write code here
        m[0] = 1;
        return dfs(root, sum, 0);
    }

private:
    std::unordered_map<int, int> m;  // <prefix_sum, count>

    int dfs(TreeNode* root, int sum, int prefix_sum) {
        if (!root) {
            return 0;
        }
        int res = 0;
        prefix_sum = prefix_sum + root->val;
        if (m.find(prefix_sum - sum) != m.end()) {
            res += m[prefix_sum - sum];
        }
        m[prefix_sum]++;
        res += dfs(root->left, sum, prefix_sum);
        res += dfs(root->right, sum, prefix_sum);
        m[prefix_sum]--;
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.FindPath(construct_tree({1, 2, 3, 4, 5, 4, 3, INT_MIN, INT_MIN, -1}), 3) << std::endl;
    return 0;
}
