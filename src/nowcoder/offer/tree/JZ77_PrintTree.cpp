/**
 * JZ77. 按之字形顺序打印二叉树
 * Source: https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=23454&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>
#include <deque>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    std::vector<std::vector<int> > Print(TreeNode* pRoot) {
        std::deque<TreeNode*> q;
        bool is_positive = true;
        if (pRoot)
            q.push_back(pRoot);
        std::vector<std::vector<int>> res;
        while (!q.empty()) {
            auto size = q.size();
            std::vector<int> line;
            for (int i = 0; i < size; i++) {
                if (is_positive) {
                    auto front = q.front();
                    q.pop_front();
                    line.push_back(front->val);
                    if (front->left)
                        q.push_back(front->left);
                    if (front->right)
                        q.push_back(front->right);
                } else {
                    auto back = q.back();
                    q.pop_back();
                    line.push_back(back->val);
                    if (back->right)
                        q.push_front(back->right);
                    if (back->left)
                        q.push_front(back->left);
                }
            }
            is_positive = !is_positive;
            res.push_back(line);
        }
        return res;
    }

};
