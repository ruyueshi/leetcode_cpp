/**
 * JZ52. 两个链表的第一个公共节点
 * Source: https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=23257&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2)
            return nullptr;
        auto p1 = pHead1;
        auto p2 = pHead2;
        while (p1 != p2) {
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }
        return p1 ? p1 : nullptr;
    }
};

int main() {
    Solution s;
    auto* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    auto* head2 = new ListNode(-1);
    head2->next = new ListNode(4);
    head2->next->next = head1->next->next;
    auto res = s.FindFirstCommonNode(head1, head2);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    return 0;
}
