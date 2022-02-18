/**
 * offer 22. 链表中倒数第k个节点
 * Source: https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < k && cur; i++)
            cur = cur->next;
        while (cur) {
            cur = cur->next;
            pre = pre->next;
        }
        return pre;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    int num[4] = {2, 3, 4, 5};
    auto p = head;
    for (auto i: num) {
        p->next = new ListNode(i);
        p = p->next;
    }
    auto res = s.getKthFromEnd(head, 2);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
