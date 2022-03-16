/**
 * 92. Reverse Linked List II
 * Source: https://leetcode-cn.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return nullptr;
        ListNode *first_tail = new ListNode(-1, head), *first_head = first_tail;
        for (int i = 0; i < left - 1; i++)
            first_tail = first_tail->next;
        ListNode *sub_head = first_tail->next, *sub_tail = sub_head, *p = sub_head->next, *temp;
        for (int i = left; i < right; i++) {
            temp = p;
            p = p->next;
            temp->next = sub_head;
            sub_head = temp;
        }
        sub_tail->next = p;
        first_tail->next = sub_head;
        return first_head->next;
    }
};

// 递归
class SolutionV2 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1)
            return reverseN(head, right);
        ListNode *reversed_list = reverseBetween(head->next, left - 1, right - 1);
        head->next = reversed_list;
        return head;
    }

private:
    ListNode *sub_head;

    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            sub_head = head->next;
            return head;
        }
        ListNode *reversed_list = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = sub_head;
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
    auto res = s.reverseBetween(l, 2, 4);
    while (res) {
        std::cout << res->val << ",";
        res = res->next;
    }
    std::cout << "\b\n";
    return 0;
}
