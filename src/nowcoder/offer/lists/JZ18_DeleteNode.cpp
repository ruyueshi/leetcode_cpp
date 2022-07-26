/**
 * JZ18. 删除链表的节点
 * Source: https://www.nowcoder.com/practice/f9f78ca89ad643c99701a7142bd59f5d?tpId=13&tqId=2273171&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        ListNode dummy_head(-1);
        dummy_head.next = head;
        auto p = &dummy_head;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return dummy_head.next;
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
    auto res = s.deleteNode(head, 1);
    while (res) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    return 0;
}
