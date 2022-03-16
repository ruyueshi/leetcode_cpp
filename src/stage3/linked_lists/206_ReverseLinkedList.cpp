/**
 * 206. Reverse Linked List
 * Source: https://leetcode-cn.com/problems/reverse-linked-list/
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 非递归
class SolutionV1 {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode *new_head = head, *p = head->next, *temp;
        new_head->next = nullptr;
        while (p) {
            temp = p;
            p = p->next;
            temp->next = new_head;
            new_head = temp;
        }
        return new_head;
    }
};

// 递归
// 相比V1，时间上并没有带来提升，空间消耗反而增大了（递归栈消耗）
// 看上去比较优雅，但是实现上有点小技巧
class SolutionV2 {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto reversed_list = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversed_list;
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> num = {1, 2, 3, 4, 5};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < num.size(); i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    auto res = s.reverseList(l);
    while (res) {
        std::cout << res->val << ",";
        res = res->next;
    }
    std::cout << "\b\n";
    l->next = nullptr;
    res = s.reverseList(l);
    while (res) {
        std::cout << res->val << ",";
        res = res->next;
    }
    std::cout << "\b\n";
    return 0;
}
