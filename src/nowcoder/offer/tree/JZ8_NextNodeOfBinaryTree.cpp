/**
 * JZ8. 二叉树的下一个结点
 * Source: https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=23451&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode) {return nullptr;}
        if (pNode->right) {
            auto find_left_child = pNode->right;
            while (find_left_child->left) {
                find_left_child = find_left_child->left;
            }
            return find_left_child;
        } else {
            auto child = pNode;
            auto parent = child->next;
            while (parent) {
                if (parent->left == child) {
                    return parent;
                }
                child = parent;
                parent = parent->next;
            }
            return nullptr;
        }
    }
};

int main() {
    return 0;
}