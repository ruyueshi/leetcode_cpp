/**
 * JZ55. 二叉树的深度
 * Source: https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=23294&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class SolutionV1 {
public:
    int TreeDepth(TreeNode *pRoot) {
        if (!pRoot) {
            return 0;
        }
        int left_depth = TreeDepth(pRoot->left);
        int right_depth = TreeDepth(pRoot->right);
        return (left_depth < right_depth ? right_depth : left_depth) + 1;
    }
};

class SolutionV2 {
public:
    int TreeDepth(TreeNode *pRoot) {
        traceback(pRoot, 0);
        return max_depth;
    }

private:
    int max_depth = 0;

    void traceback(TreeNode *pRoot, int depth) {
        if (!pRoot) {
            max_depth = std::max(depth, max_depth);
            return;
        }
        depth++;
        traceback(pRoot->left, depth);
        traceback(pRoot->right, depth);
        depth--;
    }
};

int main() {
    return 0;
}
