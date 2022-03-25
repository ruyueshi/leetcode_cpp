/**
 * 297. Serialize and Deserialize Binary Tree
 * Source: https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

#include "src/utils/tree.h"

// 速度很慢，字符串的查找查找和删除比较费时
class CodecV1 {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root) {
        return get_preorder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data) {
        return build_tree(data);
    }

private:
    std::string get_preorder(TreeNode *root) {
        if (!root)
            return "#,";
        return std::to_string(root->val) + "," + get_preorder(root->left) + get_preorder(root->right);
    }

    TreeNode *build_tree(std::string &data) {
        if (data.empty())
            return nullptr;
        if (data[0] == '#') {
            data.erase(0, 2); // 去掉开头的"#,"
            return nullptr;
        }
        auto it = data.find(',');
        auto root = new TreeNode(std::atoi(data.substr(0, it).c_str()));
        data.erase(0, it + 1);
        root->left = build_tree(data);
        root->right = build_tree(data);
        return root;
    }
};

// 使用流来处理字符串
class CodecV2 {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root) {
        if (!root)
            return "# ";
        return std::to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data) {
        if (data.empty())
            return nullptr;
        std::stringstream ss;
        ss << data;
        return build_tree(ss);
    }

private:

    TreeNode *build_tree(std::stringstream &ss) {
        std::string cur;
        ss >> cur;
        if (cur == "#")
            return nullptr;
        auto root = new TreeNode(std::atoi(cur.c_str()));
        root->left = build_tree(ss);
        root->right = build_tree(ss);
        return root;
    }
};

int main() {
    CodecV2 enc;
    auto encode_res = enc.serialize(construct_tree({1, 2, 3, INT_MIN, INT_MIN, 4, 5}));
    std::cout << encode_res << std::endl;
    print_tree1(enc.deserialize(encode_res));
    return 0;
}
