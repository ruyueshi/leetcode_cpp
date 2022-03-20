/**
 * 652. Find Duplicate Subtrees
 * Source: https://leetcode-cn.com/problems/find-duplicate-subtrees/
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>

#include "src/utils/tree.h"

class SolutionV1 {
public:
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        get_preorder(root);
        return std::vector<TreeNode *>(res.begin(), res.end());
    }

private:
    std::unordered_map<std::string, TreeNode *> hashtable;
    std::set<TreeNode *> res;

    std::string get_preorder(TreeNode *root) {
        if (!root)
            return "";
        std::string preorder = std::to_string(root->val) + ",";
        preorder += get_preorder(root->left) + "," + get_preorder(root->right) + ",";
        auto it = hashtable.find(preorder);
        if (it == hashtable.end())
            hashtable.insert({preorder, root});
        else
            res.insert(it->second);
        return preorder;
    }
};

// 简化V1
class SolutionV2 {
public:
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        get_preorder(root);
        return res;
    }

private:
    std::unordered_map<std::string, int> hashtable;  // {"1,2,4", 2}：树中有2个节点的前序遍历为"1,2,4"
    std::vector<TreeNode *> res;

    std::string get_preorder(TreeNode *root) {
        if (!root)
            return "";
        std::string preorder = std::to_string(root->val) + "," + get_preorder(root->left) + "," + get_preorder(root->right);
        if (hashtable[preorder] == 1)
            res.push_back(root);
        hashtable[preorder]++;
        return preorder;
    }
};

int main() {
    auto res = SolutionV2().findDuplicateSubtrees(construct_tree({1, 2, 3, 4, INT_MIN, 2, 4, INT_MIN, INT_MIN, 4}));
    for (auto root: res)
        print_tree1(root);
    res = SolutionV2().findDuplicateSubtrees(construct_tree({0, 0, 0, 0, INT_MIN, INT_MIN, 0, INT_MIN, INT_MIN, INT_MIN, 0}));
    for (auto root: res)
        print_tree1(root);
    res = SolutionV2().findDuplicateSubtrees(construct_tree({2, 1, 11, 11, INT_MIN, 1}));
    for (auto root: res)
        print_tree1(root);
    return 0;
}
