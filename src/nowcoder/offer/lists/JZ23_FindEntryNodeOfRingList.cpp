/**
 * JZ23. 合并两个排序的链表
 * Source: https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=23449&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* slow = pHead, *fast = pHead;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = pHead;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
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
    common_node->next->next->next = common_node;
    auto res = s.EntryNodeOfLoop(head);
    std::cout << res->val << std::endl;
    return 0;
}
