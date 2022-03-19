/**
 * 654. Maximum Binary Tree
 * Source: https://leetcode-cn.com/problems/maximum-binary-tree/
 */

#include <algorithm>
#include <vector>

#include "src/utils/tree.h"

class SolutionV1 {
public:
    TreeNode *constructMaximumBinaryTree(const std::vector<int> &nums) {
        return traceback(nums, 0, nums.size());
    }

private:
    TreeNode *traceback(const std::vector<int> &nums, int start, int end) {
        if (start >= end)
            return nullptr;
        int max_index = std::max_element(nums.begin() + start, nums.begin() + end) - nums.begin();
        auto node = new TreeNode(nums[max_index]);
        node->left = traceback(nums, start, max_index);
        node->right = traceback(nums, max_index + 1, end);
        return node;
    }
};

// 使用迭代器简化代码（实际上简化效果不明显）
class SolutionV2 {
public:
    TreeNode *constructMaximumBinaryTree(std::vector<int> &&nums) {
        return traceback(nums.begin(), nums.end());
    }

private:
    typedef std::vector<int>::iterator ptr;

    TreeNode *traceback(ptr start, ptr end) {
        if (start >= end)
            return nullptr;
        auto max_index = std::max_element(start, end);
        auto node = new TreeNode(*max_index);
        node->left = traceback(start, max_index);
        node->right = traceback(max_index + 1, end);
        return node;
    }
};

int main() {
    SolutionV2 s;
    auto root = s.constructMaximumBinaryTree({3, 2, 1, 6, 0, 5});
    print_tree1(root);
    root = s.constructMaximumBinaryTree({3, 2, 1});
    print_tree1(root);
    return 0;
}
