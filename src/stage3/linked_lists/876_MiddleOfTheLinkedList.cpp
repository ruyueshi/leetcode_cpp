/**
 * 876. Middle of the Linked List
 * Source: https://leetcode-cn.com/problems/middle-of-the-linked-list/
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 快慢指针
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    Solution s;

    std::vector<int> num = {1, 2};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < num.size(); i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    ListNode *ans = s.middleNode(l);
    std::cout << ans->val << std::endl;
    return 0;
}
