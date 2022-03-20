/**
 * 889. Construct Binary Tree from Preorder and Postorder Traversal
 * Source: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
 */

#include <algorithm>
#include <set>
#include <vector>

#include "src/utils/tree.h"

// 此方法可以找到所有情况
class SolutionV1 {
public:
    TreeNode *constructFromPrePost(const std::vector<int> &preorder, const std::vector<int> &postorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }

private:

    // 区间左闭右闭
    TreeNode *build(const std::vector<int> &preorder, int pre_start, int pre_end, const std::vector<int> &postorder, int post_start, int post_end) {
        if (pre_start > pre_end || post_start > post_end)
            return nullptr;
        int root_val = preorder[pre_start];
        auto root = new TreeNode(root_val);
        if (pre_start == pre_end)  // 若区间内只有一个节点，则其左右子树为null
            return root;
        // 查找左子树最小时的情况
        std::set<int> a, b;
        int i = 0;
        for (; i < pre_end - pre_start; i++) {
            a.insert(preorder[pre_start + 1 + i]);
            b.insert(postorder[post_start + i]);
            if (a == b) {
                break;
            }
        }
        root->left = build(preorder, pre_start + 1, pre_start + 1 + i, postorder, post_start, post_start + i);  // 区间左闭右闭
        root->right = build(preorder, pre_start + i + 2, pre_end, postorder, post_start + i + 1, post_end - 1);
        return root;
    }
};

// labupadong的方法，把preorder[pre_start+1]作为左子树的根节点，速度更快
class SolutionV2 {
public:
    TreeNode *constructFromPrePost(const std::vector<int> &preorder, const std::vector<int> &postorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }

private:
    // 区间左闭右闭
    TreeNode *build(const std::vector<int> &preorder, int pre_start, int pre_end, const std::vector<int> &postorder, int post_start, int post_end) {
        if (pre_start > pre_end || post_start > post_end)
            return nullptr;
        int root_val = preorder[pre_start];
        auto root = new TreeNode(root_val);
        if (pre_start == pre_end)  // 若区间内只有一个节点，则其左右子树为null
            return root;

        int left_root_index_in_pre = pre_start + 1;
        int left_root_index_in_post = std::find(postorder.begin() + post_start, postorder.begin() + post_end + 1, preorder[left_root_index_in_pre]) - postorder.begin();
        int left_size = left_root_index_in_post - post_start + 1;
        root->left = build(preorder, left_root_index_in_pre, left_root_index_in_pre + left_size - 1, postorder, post_start, left_root_index_in_post);  // 区间左闭右闭
        root->right = build(preorder, left_root_index_in_pre + left_size, pre_end, postorder, left_root_index_in_post + 1, post_end - 1);
        return root;
    }
};

int main() {
    SolutionV2 s;
    auto root = s.constructFromPrePost({1, 2, 4, 5, 3, 6, 7}, {4, 5, 2, 6, 7, 3, 1});
    print_tree1(root);
    root = s.constructFromPrePost({-1}, {-1});
    print_tree1(root);
    return 0;
}
