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

class SolutionV1 {
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

// 使用递归
// 后序遍历
class SolutionV2 {
public:
    bool isPalindrome(ListNode *head) {
        left = head;
        return traverse(head);
    }

private:
    ListNode* left;

    bool traverse(ListNode *right) {
        if (!right)
            return true;
        bool right_res = traverse(right->next);
        if (right_res && left->val == right->val) {
            left = left->next;
            return true;
        } else {
            return false;
        }
    }
};

// 数学方法
// 非常精妙、简洁
class SolutionV3 {
public:
    bool isPalindrome(ListNode *head) {
        unsigned long long s1 = 0, s2 = 0, t = 1;
        auto p = head;
        while (p) {
            s1 = s1 * 10 + p->val;
            s2 = p->val * t + s2;
            t *= 10;
            p = p->next;
        }
        return s1 == s2;
    }
};

int main() {
    SolutionV3 s;
    std::vector<int> num = {1, 2, 3, 3, 2, 1};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < num.size(); i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    std::cout << s.isPalindrome(l) << std::endl;
    return 0;
}
