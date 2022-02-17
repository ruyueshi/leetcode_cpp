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
    ListNode *deleteNode(ListNode *head, int val) {
        if (!head)
            return nullptr;
        if (head->val == val)
            return head->next;
        ListNode *p = head;
        while (p) {
            if (p->next && p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return head;
    }

    ListNode* deleteNodeV2(ListNode* head, int val) {
        if(!head) return nullptr;
        if(head->val == val) return head->next;
        head->next = deleteNode(head->next,val);
        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(4);
    int num[3] = {5,1,9};
    auto p = head;
    for (auto i: num) {
        p->next = new ListNode(i);
        p = p->next;
    }
    auto res = s.deleteNodeV2(head, 4);
    while (res) {
        std::cout << res->val << "->";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
