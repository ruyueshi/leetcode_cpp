/**
 * 21. Merge Two Sorted Lists
 * Source: https://leetcode-cn.com/problems/merge-two-sorted-lists/
 */

#ifndef SOLUTION021_H
#define SOLUTION021_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class solution021 {
public:
    // 8 ms, 14.5 MB
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return !l1 ? l2 : l1;
        }
        ListNode *head, *p;
        ListNode *p1 = l1, *p2 =l2;
        if (p1->val <= p2->val) {
            head = new ListNode(p1->val);
            p1 = p1->next;
        } else {
            head = new ListNode(p2->val);
            p2 = p2->next;
        }
        p = head;
        while (p1 || p2) {
            if (!p1) {
                while (p2) {
                    p->next = new ListNode(p2->val);
                    p = p->next;
                    p2 = p2->next;
                }
                break;
            } else if (!p2) {
                while (p1) {
                    p->next = new ListNode(p1->val);
                    p = p->next;
                    p1 = p1->next;
                }
                break;
            } else {
                if (p1->val <= p2->val) {
                    p->next = new ListNode(p1->val);
                    p = p->next;
                    p1 = p1->next;
                } else {
                    p->next = new ListNode(p2->val);
                    p = p->next;
                    p2 = p2->next;
                }
            }
        }

        return head;
    }

    // 8 ms, 14.2 MB, which takes up less memory
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return !l1 ? l2 : l1;
        }
        ListNode *head, *p1, *p2;
        if (l1->val <= l2->val) {
            head = l1;
            p1 = l1->next;
            p2 = l2;
        } else {
            head = l2;
            p1 = l1;
            p2 = l2->next;
        }
        ListNode *pre = head;

        while (p1 || p2) {
            if (!p1) { // l1 traverse over
                pre->next = p2;
                break;
            } else if (!p2) { // l2 traverse over
                pre->next = p1;
                break;
            } else {
                if (p1->val <= p2->val) {
                    pre->next = p1;
                    pre = pre->next;
                    p1 = p1->next;
                } else {
                    pre->next = p2;
                    pre = pre->next;
                    p2 = p2->next;
                }
            }
        }
        return head;
    }
};

void test_solution021() {
    solution021 s;
    int num1[] = {1,2,4};
    int num2[] = {1,3,4};
    ListNode *l1 = new ListNode(num1[0]);
    ListNode *l2 = new ListNode(num2[0]);
    ListNode *p1 = l1, *p2 = l2;
    for (int i = 1; i < 3; i++) {
        p1->next = new ListNode(num1[i]);
        p1 = p1->next;
        p2->next = new ListNode(num2[i]);
        p2 = p2->next;
    }
    ListNode *ans = s.mergeTwoLists2(l1, l2);
    while (ans) {
        std::cout << ans->val << "->";
        ans = ans->next;
    }
    std::cout << std::endl;
}

#endif // SOLUTION021_H
