#ifndef LEETCODE_CPP_TREE_H
#define LEETCODE_CPP_TREE_H

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * nodes = {3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1}; // INT_MIN means null node;
 */
static TreeNode *construct_tree(const std::vector<int> &nodes) {
    if (nodes.size() == 0)
        return nullptr;
    auto root = new TreeNode(nodes[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        auto p = q.front();
        q.pop();
        if (nodes[i] != INT_MIN) {
            p->left = new TreeNode(nodes[i]);
            q.push(p->left);
        }
        if (i + 1 < nodes.size() && nodes[i + 1] != INT_MIN) {
            p->right = new TreeNode(nodes[i + 1]);
            q.push(p->right);
        }
        i += 2;
    }
    return root;
}

static void print_tree1(TreeNode *root) {
    if (!root) {
        std::cout << "[]\n";
        return;
    }
    std::queue<TreeNode *> q;
    std::vector<int> res;
    q.push(root);
    res.push_back(root->val);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (!p->left && !p->right && q.empty())
            break;
        if (p->left) {
            res.push_back(p->left->val);
            q.push(p->left);
        } else {
            res.push_back(INT_MIN);
        }
        if (p->right) {
            res.push_back(p->right->val);
            q.push(p->right);
        } else {
            res.push_back(INT_MIN);
        }
    }
    while (res.back() == INT_MIN)
        res.pop_back();
    std::cout << "[";
    for (const auto &v: res) {
        std::cout << (v == INT_MIN ? "null" : std::to_string(v)) << ",";
    }
    std::cout << "\b]\n";
}

// static void traceback(TreeNode *root, int level, std::vector<std::string> &tree) {
//     if (level >= tree.size() / 2) {
//         tree.emplace_back(std::to_string(root->val));
//     }
//
//     if (root->left) {
//         if (level >= tree.size() / 2) {
//             tree.emplace_back("|");
//         } else {
//             tree[2 * level + 1] += "|";
//         }
//         traceback(root->left, level + 1, tree);
//     } else {
//         if (level >= tree.size() / 2) {
//             tree.emplace_back(" ");
//         } else {
//             tree[2 * level + 1] += " ";
//         }
//     }
//
//     if (root->right) {
//         if (level >= tree.size() / 2) {
//             tree.emplace_back("\\");
//         } else {
//             tree[2 * level + 1] += "\\";
//         }
//         traceback(root->right, level + 1, tree);
//     } else {
//         if (level >= tree.size() / 2) {
//             tree.emplace_back("\\");
//         } else {
//             tree[2 * level + 1] += "\\";
//         }
//     }
// }
//
// static void print_tree2(TreeNode *root) {
//     std::vector<std::string> tree;
//     traceback(root, 0, tree);
// }

#endif //LEETCODE_CPP_TREE_H
