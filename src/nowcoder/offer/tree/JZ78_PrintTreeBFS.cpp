/**
 * JZ78 把二叉树打印成多行
 * Source: https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=23453&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <vector>
#include <queue>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int>> Print(TreeNode* pRoot) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> res;
        if (pRoot)
            q.push(pRoot);
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> layer;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                layer.push_back(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            res.push_back(layer);
        }
        return res;
    }

};
