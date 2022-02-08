/**
 * offer 35. 复杂链表的复制
 * Source: https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
 */

#include <iostream>
#include <map>
#include <vector>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 哈希表
// 时间复杂度O(N)：遍历两次链表
// 空间复杂度O(N)：哈希表使用线性大小的空间
class SolutionV1 {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        std::map<Node*, Node*> m;
        Node* p = head;
        while (p) {
            m[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while (p) {
            m[p]->next = m[p->next];
            m[p]->random = m[p->random];
            p = p->next;
        }
        return m[head];
    }
};

// 拼接与拆分
// 时间复杂度O(N)：遍历三次链表
// 空间复杂度O(1)：使用常数大小的额外空间
class SolutionV2 {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        Node *p = head;
        // 将新节点插入原链表
        while (p) {
            Node *new_node = new Node(p->val);
            new_node->next = p->next;
            p->next = new_node;
            p = new_node->next;
        }
        // 构建random指针
        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : nullptr;  // 新节点为p->next
            p = p->next->next;
        }
        // 拆分链表
        Node *new_head = head->next;
        p = head;
        Node *q = new_head;
        while (p) {
            p->next = q->next;
            p = p->next;
            if (p) {
                q->next = p->next;
                q = q->next;
            } else {
                q = nullptr;
            }
        }
        return new_head;
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> a = {1,2,3,4};
    Node* head = new Node(0);
    Node* p = head;
    Node* q = head;
    for (auto i: a) {
        p->next = new Node(i);
        p = p->next;
        p->random = q;
        q = p;
    }
    auto res = s.copyRandomList(head);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    return 0;
}
