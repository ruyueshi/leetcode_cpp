/**
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Source: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */

#include <algorithm>
#include <unordered_set>
#include <vector>

#include "src/utils/tree.h"

class SolutionV1 {
public:
    TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
        preorder_start = 0;
        return build(preorder, inorder, 0, inorder.size());
    }

private:
    int preorder_start;

    TreeNode *build(const std::vector<int> &preorder, const std::vector<int> &inorder, int inorder_start, int inorder_end) {
        if (preorder_start >= preorder.size() || inorder_start >= inorder_end)
            return nullptr;
        int root_index_in_inorder = -1;
        for (int i = inorder_start; i < inorder_end; i++) {
            if (preorder[preorder_start] == inorder[i]) {
                root_index_in_inorder = i;
                break;
            }
        }
        if (root_index_in_inorder == -1)
            return nullptr;

        auto root = new TreeNode(preorder[preorder_start]);
        preorder_start++;
        root->left = build(preorder, inorder, inorder_start, root_index_in_inorder);
        root->right = build(preorder, inorder, root_index_in_inorder + 1, inorder_end);
        return root;
    }
};

class SolutionV2 {
public:
    TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
        preorder_start = 0;
        preorder_index_in_inorder.resize(preorder.size());
        // 其实此操作比较耗时，O(n^2)
        for (int i = 0; i < preorder.size(); i++) {
            preorder_index_in_inorder[i] = std::find(inorder.begin(), inorder.end(), preorder[i]) - inorder.begin();
        }
        return build(preorder, inorder, 0, inorder.size());
    }

private:
    std::vector<int> preorder_index_in_inorder;
    int preorder_start;

    TreeNode *build(const std::vector<int> &preorder, const std::vector<int> &inorder, int inorder_start, int inorder_end) {
        if (preorder_start >= preorder.size() || inorder_start >= inorder_end)
            return nullptr;
        int root_index_in_inorder = preorder_index_in_inorder[preorder_start];
        if (root_index_in_inorder < inorder_start || root_index_in_inorder >= inorder_end)
            return nullptr;

        auto root = new TreeNode(preorder[preorder_start]);
        preorder_start++;
        root->left = build(preorder, inorder, inorder_start, root_index_in_inorder);
        root->right = build(preorder, inorder, root_index_in_inorder + 1, inorder_end);
        return root;
    }
};

// labuladong的解法
// 更加简介，效率稍高
class SolutionV3 {
public:
    TreeNode *buildTree(const std::vector<int> &preorder, const std::vector<int> &inorder) {
        int n = preorder.size();
        return build(preorder, 0, n, inorder, 0, n);
    }

private:

    // 区间左闭右开
    TreeNode *build(const std::vector<int> &preorder, int pre_start, int pre_end, const std::vector<int> &inorder, int in_start, int in_end) {
        if (pre_start >= pre_end || in_start >= in_end)
            return nullptr;

        int root_val = preorder[pre_start];
        int root_index = std::find(inorder.begin() + in_start, inorder.begin() + in_end, root_val) - inorder.begin();
        auto root = new TreeNode(root_val);
        int left_size = root_index - in_start;
        root->left = build(preorder, pre_start + 1, pre_start + left_size + 1, inorder, in_start, root_index);  // 区间左闭右开
        root->right = build(preorder, pre_start + left_size + 1, pre_end, inorder, root_index + 1, in_end);
        return root;
    }
};

int main() {
    auto root = SolutionV3().buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
    print_tree1(root);
    root = SolutionV3().buildTree({-1}, {-1});
    print_tree1(root);
    return 0;
}
