/**
 * 142. Linked List Cycle II
 * Source: https://leetcode-cn.com/problems/linked-list-cycle-ii/
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

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (slow) {
                    if (fast == slow)
                        return slow;
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        return nullptr;
    }
};

int main() {
    Solution s;
    std::vector<int> num = {1, 2, 3, 4};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < num.size(); i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    p->next = l;
    auto res = s.detectCycle(l);
    std::cout << res->val << std::endl;
    return 0;
}
