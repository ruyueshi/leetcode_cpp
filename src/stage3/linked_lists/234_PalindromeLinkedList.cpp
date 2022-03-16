/**
 * 234. Palindrome Linked List
 * Source: https://leetcode-cn.com/problems/palindrome-linked-list/
 */

#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow = head;
        std::stack<int> s;
        s.push(slow->val);
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            s.push(slow->val);
        }
        if (!fast) { // 说明是双数, 删除中间的两个数
            int m = s.top();
            s.pop();
            if (m != s.top())
                return false;
            s.pop();
        } else if (!fast->next) { // 说明是单数，删除中间的数
            s.pop();
        }
        slow = slow->next;
        while (slow) {
            if (slow->val != s.top())
                return false;
            slow = slow->next;
            s.pop();
        }
        return true;
    }
};

int main() {
    Solution s;
    std::vector<int> num = {1, 2, 3, 4, 2, 1};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < num.size(); i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    std::cout << s.isPalindrome(l) << std::endl;
    return 0;
}
