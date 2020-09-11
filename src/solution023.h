/**
 * 24. Swap Nodes in Pairs
 * Source: https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 */

#ifndef SOLUTION023_H
#define SOLUTION023_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class solution023 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* p = new_head;
        while (p) {
            ListNode* q = p->next;
            if (q && q->next) {
                ListNode* n = q->next;
                p->next = n;
                q->next = n->next;
                n->next = q;
                p = p->next;
            }
            p = p->next;
        }
        return new_head->next;
    }
};

void test_solution023() {
    solution023 s;
    int num[] = {1,2,3,4};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < 4; i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    ListNode *ans = s.swapPairs(l);
    while (ans) {
        std::cout << ans->val << "->";
        ans = ans->next;
    }
    std::cout << std::endl;
}

#endif // SOLUTION023_H
