/**
 * JZ26. 反转链表
 * Source: https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=23286&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
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
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead)
            return nullptr;
        auto head = pHead;
        auto p = pHead->next;
        head->next = nullptr;
        while (p)  {
            auto q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};

int main() {
    Solution s;
    auto* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    auto res = s.ReverseList(head);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    return 0;
}
