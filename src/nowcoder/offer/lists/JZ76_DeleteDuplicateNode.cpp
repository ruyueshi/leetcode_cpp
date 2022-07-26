/**
 * JZ76. 删除链表中重复的节点
 * Source: https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=23450&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode dummy(-1);
        dummy.next = pHead;
        auto p = dummy.next;
        auto p_p = &dummy;  // parent of p;
        bool is_duplicate = false;
        while (p && p->next) {
            while (p->next && p->next->val == p->val) {
                p->next = p->next->next;
                is_duplicate = true;
            }
            if (is_duplicate) {
                p_p->next = p->next;
                p = p->next;
                is_duplicate = false;
            } else {
                p = p->next;
                p_p = p_p->next;
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution s;
    auto* head = new ListNode(1);
    head->next = new ListNode(2);
    auto* common_node = new ListNode(3);
    head->next->next = common_node;
    common_node->next = new ListNode(3);
    common_node->next->next = new ListNode(4);
    auto res = s.deleteDuplication(head);
    while (res) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    return 0;
}
