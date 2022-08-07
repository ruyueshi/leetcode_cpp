/**
 * JZ36. 二叉搜索树与双向链表
 * Source: https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=23253&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"

using namespace std;

class SolutionV1 {
public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        return traverse(pRootOfTree);
    }

public:
    TreeNode *traverse(TreeNode *root) {
        if (!root) {return nullptr;}
        auto left = traverse(root->left);
        auto right = traverse(root->right);
        if (!left) {
            root->left = nullptr;
            left = root;
        } else {
            auto left_end = left;
            while (left_end->right) {
                left_end = left_end->right;
            }
            left_end->right = root;
            root->left = left_end;
        }
        root->right = right;
        if (right) { right->left = root; }
        return left;
    }
};

class SolutionV2 {
public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (!pRootOfTree) {return nullptr;}
        pre_node = nullptr;
        TreeNode *head = pRootOfTree;
        while (head->left) {head = head->left;}
        inorder(pRootOfTree);
        return head;
    }

public:
    TreeNode* pre_node;
    void inorder(TreeNode *root) {
        if (!root) {return;}
        inorder(root->left);
        if (pre_node) {
            pre_node->right = root;
        }
        root->left = pre_node;
        pre_node = root;
        inorder(root->right);
    }
};

int main() {
    SolutionV2 s;
    auto p = s.Convert(construct_tree({10, 6, 14, 4, 8, 12, 16}));
    while (p) {
        std::cout << p->val << ",";
        p = p->right;
    }
    return 0;
}
