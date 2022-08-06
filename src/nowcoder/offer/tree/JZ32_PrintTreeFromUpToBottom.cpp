/**
 * JZ32. 从上往下打印二叉树
 * Source: https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=23280&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"
#include "src/utils/print.h"

#include <queue>

using namespace std;

class Solution {
public:
    std::vector<int> PrintFromTopToBottom(TreeNode *root) {
        if (!root) {
            return {};
        }
        std::vector<int> res;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                res.push_back(p->val);
                if (p->left) { q.push(p->left); }
                if (p->right) { q.push(p->right); }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    print_vector(s.PrintFromTopToBottom(construct_tree({8, 6, 10, INT_MIN, INT_MIN, 2, 1})));
    return 0;
}
