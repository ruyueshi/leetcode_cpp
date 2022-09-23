/**
 * JZ86 在二叉树中找到两个节点的最近公共祖先
 * Source: https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116?tpId=13&tqId=1024325&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <algorithm>
#include <vector>
#include "src/utils/tree.h"

class Solution {
public:
    int lowestCommonAncestor(TreeNode *root, int p, int q) {
        f_p = f_q = false;
        std::vector<int> v_p, v_q;
        traceback(root, p, q, v_p, v_q);
        int len1 = v_p.size(), len2 = v_q.size();
        int pre = v_p.front();
        for (int i = 1; i < std::min(len1, len2); i++) {
            if (v_p[i] != v_q[i]) {
                return pre;
            }
            pre = v_p[i];
        }
        return pre;
    }

private:
    bool f_p, f_q;

    void traceback(TreeNode *root, int p, int q, std::vector<int> &v_p, std::vector<int> &v_q) {
        if (!root || f_p && f_q) {
            return;
        }
        if (root->val == p) {
            v_p.push_back(root->val);
            f_p = true;
        } else if (root->val == q) {
            v_q.push_back(root->val);
            f_q = true;
        }
        if (!f_p) {
            v_p.push_back(root->val);
        }
        if (!f_q) {
            v_q.push_back(root->val);
        }
        traceback(root->left, p, q, v_p, v_q);
        traceback(root->right, p, q, v_p, v_q);
        if (!f_p) {
            v_p.pop_back();
        }
        if (!f_q) {
            v_q.pop_back();
        }
    }
};

int main() {
    Solution s;
    std::cout
            << s.lowestCommonAncestor(construct_tree(
                    {5, 14, INT_MIN, INT_MIN, 9, INT_MIN, 12, 15, INT_MIN, INT_MIN, 1, INT_MIN, 3, INT_MIN, 7, 10, INT_MIN, INT_MIN, 11, 8, INT_MIN, 13, INT_MIN, 4, 6, INT_MIN, 0, INT_MIN, INT_MIN,
                     2}), 11,
                                      10) << std::endl;
    return 0;
}
