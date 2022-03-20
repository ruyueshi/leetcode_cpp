/**
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 * Source: https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */

#include <algorithm>
#include <vector>

#include "src/utils/tree.h"

class Solution {
public:
    TreeNode *buildTree(const std::vector<int> &inorder, const std::vector<int> &postorder) {
        int n = inorder.size();
        return build(inorder, 0, n, postorder, 0, n);
    }

private:

    // 区间左闭右开
    TreeNode *build(const std::vector<int> &inorder, int in_start, int in_end, const std::vector<int> &postorder, int post_start, int post_end) {
        if (in_start >= in_end || post_start >= post_end)
            return nullptr;
        int root_val = postorder[post_end - 1];
        int root_index = std::find(inorder.begin() + in_start, inorder.begin() + in_end, root_val) - inorder.begin();
        auto root = new TreeNode(root_val);
        int left_size = root_index - in_start;
        root->left = build(inorder, in_start, root_index, postorder, post_start, post_start + left_size);  // 区间左闭右开
        root->right = build(inorder, root_index + 1, in_end, postorder, post_start + left_size, post_end - 1);
        return root;
    }
};

int main() {
    Solution s;
    auto root = s.buildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3});
    print_tree1(root);
    root = s.buildTree({-1}, {-1});
    print_tree1(root);
    return 0;
}
