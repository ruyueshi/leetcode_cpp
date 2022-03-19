#ifndef LEETCODE_CPP_TREE_H
#define LEETCODE_CPP_TREE_H

#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * nodes = {3,0,4,-1,2,-1,-1,1}; // -1 means null node;
 */
static TreeNode *construct_tree(const std::vector<int> &nodes) {
    if (nodes.size() == 0)
        return nullptr;
    auto root = new TreeNode(nodes[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    for (int i = 1; i < nodes.size(); i++) {
        auto p = q.front();
        q.pop();
        if (nodes[i] >= 0) {
            p->left = new TreeNode(nodes[i]);
            q.push(p->left);
        }
        if (++i >= nodes.size())
            break;
        if (nodes[i] >= 0) {
            p->right = new TreeNode(nodes[i]);
            q.push(p->right);
        }
    }
    return root;
}

static void print_tree1(TreeNode *root) {
    if (!root) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    std::cout << "[" << root->val;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (!p->left && !p->right && q.empty())
            break;
        if (p->left) {
            std::cout << "," << p->left->val;
            q.push(p->left);
        } else {
            std::cout << ",null";
        }
        if (p->right) {
            std::cout << "," << p->right->val;
            q.push(p->right);
        } else {
            std::cout << ",null";
        }
    }
    std::cout << "]\n";
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
