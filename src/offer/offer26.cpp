/**
 * offer 26. 树的子结构
 * Source: https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
 */

#include <iostream>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归
class SolutionV1 {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (!B)
            return false;
        std::queue<TreeNode *> q;
        if (A)
            q.push(A);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (this->isSame(p, B))
                return true;
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        return false;
    }

private:
    bool isSame(TreeNode *t1, TreeNode *t2) {
        if (t2 == nullptr)
            return true;
        else if (t1 == nullptr || t1->val != t2->val)
            return false;
        else
            return this->isSame(t1->left, t2->left) && this->isSame(t1->right, t2->right);
    }
};

// 递归
// 优化V1
class SolutionV2 {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (!A || !B)
            return false;
        return this->isSame(A, B) || this->isSubStructure(A->left, B) || this->isSubStructure(A->right, B);
    }

private:
    bool isSame(TreeNode *t1, TreeNode *t2) {
        if (t2 == nullptr)
            return true;
        else if (t1 == nullptr || t1->val != t2->val)
            return false;
        else
            return this->isSame(t1->left, t2->left) && this->isSame(t1->right, t2->right);
    }
};

int main() {
    auto root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    auto B = new TreeNode(4);
    B->right = new TreeNode(2);
    std::cout << SolutionV2().isSubStructure(root, B) << std::endl;
    return 0;
}
