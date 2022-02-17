/**
 * offer 18. 删除链表的节点
 * Source: https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 建立新的链表，空间复杂度O(N)
    ListNode* mergeTwoListsV1(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        else if (!(l1 && l2))
            return l1 ? l1 : l2;
        else {
            ListNode *head, *p;
            if (l1->val <= l2->val) {
                head = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                head = new ListNode(l2->val);
                l2 = l2->next;
            }
            p = head;
            while (l1 && l2) {
                if (l1->val <= l2->val) {
                    p->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    p->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
                p = p->next;
            }
            if (l1)
                p->next = l1;
            else if (l2)
                p->next = l2;
            return head;
        }
    }

    // 递归法：在原链表上进行修改，空间复杂度O(1)
    ListNode* mergeTwoListsV2(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        else if (!(l1 && l2))
            return l1 ? l1 : l2;
        else {
            ListNode *p1, *p2;
            if (l1->val <= l2->val)
                p1 = l1, p2 = l2;
            else
                p1 = l2, p2 = l1;
            p1->next = mergeTwoListsV2(p1->next, p2);
            return p1;
        }
    }

    // 优化V2
    ListNode* mergeTwoListsV2_1(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoListsV2_1(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoListsV2_1(l2->next, l1);
            return l2;
        }
    }

    // 非递归：在原链表上进行修改，空间复杂度O(1)
    ListNode* mergeTwoListsV3(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        else if (!(l1 && l2))
            return l1 ? l1 : l2;
        else {
            ListNode *p1, *p2, *head;
            if (l1->val <= l2->val)
                head = l1, p1 = l1->next, p2 = l2;
            else
                head = l2, p1 = l2->next, p2 = l1;
            ListNode *p = head;
            while (p1 && p2) {
                while (p1 && p1->val <= p2->val) {
                    p->next = p1;
                    p1 = p1->next;
                    p = p->next;
                }
                if (!p1)
                    break;
                while (p2 && p2->val <= p1->val) {
                    p->next = p2;
                    p2 = p2->next;
                    p = p->next;
                }
            }
            if (p1)
                p->next = p1;
            else if (p2)
                p->next = p2;
            return head;
        }
    }

    // 优化V3
    ListNode* mergeTwoListsV3_1(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        else if (l2)
            p->next = l2;
        return head->next;
    }
};

int main() {
    Solution s;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    auto res = s.mergeTwoListsV3_1(head1, head2);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    std::cout << std::endl;
    head1 = new ListNode(5);
    head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(4);
    res = s.mergeTwoListsV3_1(head1, head2);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
