/**
 * JZ37 序列化二叉树
 * Source: https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=23455&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <vector>
#include <queue>
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    char* Serialize(TreeNode *root) {
        res = preorder(root);
        return const_cast<char *>(res.c_str());
    }

    TreeNode* Deserialize(char *str) {
        if (!str) {
            return nullptr;
        }
        std::stringstream ss;
        ss << str;
        return build(ss);
    }

private:
    std::string res;

    std::string preorder(TreeNode *root) {
        if (!root) {
            return "# ";
        }
        return std::to_string(root->val) + " " + preorder(root->left) + preorder(root->right);
    }

    TreeNode* build(std::stringstream &ss) {
        std::string cur;
        ss >> cur;
        if (cur == "#") {
            return nullptr;
        }
        auto root = new TreeNode(std::atoi(cur.c_str()));
        root->left = build(ss);
        root->right = build(ss);
        return root;
    }
};

