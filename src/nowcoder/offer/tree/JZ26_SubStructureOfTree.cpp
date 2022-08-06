/**
 * JZ26. 树的子结构
 * Source: https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=23282&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"

using namespace std;

class Solution {
public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (!pRoot1 || !pRoot2) {
            return false;
        } else {
            return judge(pRoot1, pRoot2);
        }
    }

private:
    bool judge(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (!pRoot2) {
            return true;
        } else if (!pRoot1) {
            return false;
        } else {
            return pRoot1->val == pRoot2->val && judge(pRoot1->left, pRoot2->left) &&
                   judge(pRoot1->right, pRoot2->right) ||
                   judge(pRoot1->left, pRoot2) || judge(pRoot1->right, pRoot2);
        }
    }
};

int main() {
    Solution s;
    std::cout << s.HasSubtree(construct_tree({8, 8, 7, 9, 2, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 4, 7}),
                              construct_tree({8, 9, 2}))
              << std::endl;
    return 0;
}
