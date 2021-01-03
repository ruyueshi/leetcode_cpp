/**
 * 19. Remove Nth Node From End of List
 * Source: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 */

#ifndef SOLUTION019_H
#define SOLUTION019_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class solution019 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        int dist = 0;
        while (q->next) {
            if (dist < n) {
                q = q->next;
                dist++;
            } else {
                p = p->next;
                q = q->next;
            }
        }

        if (dist == n) {
            q = p->next;
            p->next = q->next;
            delete q;
            q = NULL;
        } else {
            head = p->next;
            delete p;
            p = NULL;
        }
        return head;
    }
};

static void test_solution019() {
    solution019 s;
    ListNode *head = new ListNode(1);
    ListNode *t = head;
//    for (int x = 2; x <= 5; x++) {
//        t->next = new ListNode(x);
//        t = t->next;
//    }
    t = s.removeNthFromEnd(head, 1);
    while (t) {
        std::cout << t->val << "->";
        t = t->next;
    }
    std::cout << std::endl;
}

#endif // SOLUTION019_H
