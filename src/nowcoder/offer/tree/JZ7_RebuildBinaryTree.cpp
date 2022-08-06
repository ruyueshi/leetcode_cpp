/**
 * JZ7. 重建二叉树
 * Source: https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=23282&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int size = pre.size();
        return build_tree(pre, 0, size, vin, 0, size);
    }

private:
    TreeNode *
    build_tree(const std::vector<int> &pre, int pre_start, int pre_end, const std::vector<int> &vin, int in_start,
               int in_end) {
        if (pre_start >= pre_end || in_start >= in_end) {
            return nullptr;
        }
        int root_val = pre[pre_start];
        int root_index = std::find(vin.begin() + in_start, vin.end() + in_end, root_val) - vin.begin();
        int left_tree_size = root_index - in_start;
        int right_tree_size = in_end - 1 - root_index;
        TreeNode *root = new TreeNode(root_val);
        root->left = build_tree(pre, pre_start + 1, pre_start + 1 + left_tree_size,
                                vin, in_start, root_index);
        root->right = build_tree(pre, pre_start + 1 + left_tree_size, pre_start + 1 + left_tree_size + right_tree_size,
                                 vin, root_index + 1, root_index + 1 + right_tree_size);
        return root;
    }
};

int main() {
    Solution s;
    std::vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8}, vin = {4, 7, 2, 1, 5, 3, 8, 6};
    print_tree1(s.reConstructBinaryTree(pre, vin));
    return 0;
}
