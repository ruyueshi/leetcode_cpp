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
    std::unordered_set<int> visited;
    int preorder_start;

    TreeNode *build(const std::vector<int> &preorder, const std::vector<int> &inorder, int inorder_start, int inorder_end) {
        if (preorder_start >= preorder.size() || inorder_start >= inorder_end || visited.find(preorder[preorder_start]) != visited.end())
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
        visited.insert(preorder[preorder_start]);
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
        for (int i = 0 ; i < preorder.size(); i++) {
            preorder_index_in_inorder[i] = std::find(inorder.begin(), inorder.end(), preorder[i]) - inorder.begin();
        }
        return build(preorder, inorder, 0, inorder.size());
    }

private:
    std::vector<int> preorder_index_in_inorder;
    std::unordered_set<int> visited;
    int preorder_start;

    TreeNode *build(const std::vector<int> &preorder, const std::vector<int> &inorder, int inorder_start, int inorder_end) {
        if (preorder_start >= preorder.size() || inorder_start >= inorder_end || visited.find(preorder[preorder_start]) != visited.end())
            return nullptr;
        int root_index_in_inorder = preorder_index_in_inorder[preorder_start];
        if (root_index_in_inorder < inorder_start || root_index_in_inorder >= inorder_end)
            return nullptr;

        auto root = new TreeNode(preorder[preorder_start]);
        visited.insert(preorder[preorder_start]);
        preorder_start++;
        root->left = build(preorder, inorder, inorder_start, root_index_in_inorder);
        root->right = build(preorder, inorder, root_index_in_inorder + 1, inorder_end);
        return root;
    }
};

int main() {
    auto root = SolutionV2().buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
    print_tree1(root);
    root = SolutionV2().buildTree({-1}, {-1});
    print_tree1(root);
    return 0;
}
