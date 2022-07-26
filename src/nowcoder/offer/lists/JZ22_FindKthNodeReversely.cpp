/**
 * JZ22. 链表中倒数第K个结点
 * Source: https://www.nowcoder.com/practice/886370fe658f41b498d40fb34ae76ff9?tpId=13&tqId=1377477&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
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
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        auto p = pHead;
        int i = 0;
        while (p && i < k) {
            p = p->next;
            i++;
        }
        if (!p && i < k)
            return nullptr;
        auto q = pHead;
        while (p) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};

int main() {
    Solution s;
    auto* head = new ListNode(1);
    head->next = new ListNode(2);
    auto* common_node = new ListNode(3);
    head->next->next = common_node;
    common_node->next = new ListNode(4);
    common_node->next->next = new ListNode(5);
    auto res = s.FindKthToTail(head, 3);
    std::cout << res->val << std::endl;
    return 0;
}
