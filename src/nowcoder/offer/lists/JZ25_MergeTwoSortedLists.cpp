/**
 * JZ25. 合并两个排序的链表
 * Source: https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=23267&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <stack>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1)
            return pHead1;
        if (!pHead2)
            return pHead1;
        ListNode dummy_head(-1);
        ListNode* p = &dummy_head;
        while (pHead1 && pHead2) {
            ListNode* q;
            if (pHead1->val <= pHead2->val) {
                p->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        p->next = pHead1 ? pHead1 : pHead2;
        return dummy_head.next;
    }
};

int main() {
    Solution s;
    auto* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    auto* head2 = new ListNode(-1);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(5);
    auto res = s.Merge(head1, head2);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    return 0;
}
