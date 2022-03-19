/**
 * 116. Populating Next Right Pointers in Each Node
 * Source: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 */

#include <iostream>
#include <queue>

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

// 层序遍历
class SolutionV1 {
public:
    Node *connect(Node *root) {
        std::queue<Node *> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node *pre = nullptr;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                if (i == 0) {
                    pre = p;
                } else {
                    pre->next = p;
                    pre = pre->next;
                }

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return root;
    }
};

// 充分利用题目所给条件：完美二叉树，即每个父节点都有两个子节点
class SolutionV2 {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return nullptr;
        connectTwoNode(root->left, root->right);
        return root;
    }

    // 辅助函数
    void connectTwoNode(Node *node1, Node *node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return;
        }
        /**** 前序遍历位置 ****/
        // 将传入的两个节点连接
        node1->next = node2;

        // 连接相同父节点的两个子节点
        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);
        // 连接跨越父节点的两个子节点
        connectTwoNode(node1->right, node2->left);
    }
};

int main() {
    SolutionV2 s;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    auto res = s.connect(root);
    std::queue<Node *> q;
    if (res)
        q.push(res);
    while (!q.empty()) {
        int size = q.size();
        Node *start = nullptr;
        for (int i = 0; i < size; i++) {
            auto p = q.front();
            q.pop();
            if (i == 0) {
                start = p;
            }
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        while (start) {
            std::cout << start->val << "->";
            start = start->next;
        }
        std::cout << "#\n";
    }
    return 0;
}
