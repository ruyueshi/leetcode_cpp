/**
 * offer 24. 反转链表
 * Source: https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* p = head->next;
        head->next = NULL;
        while (p) {
            ListNode* q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};

int main() {
    Solution s;
    std::vector<int> a = {1,2,3,4};
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (auto i: a) {
        p->next = new ListNode(i);
        p = p->next;
    }
    auto res = s.reverseList(head);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    return 0;
}
