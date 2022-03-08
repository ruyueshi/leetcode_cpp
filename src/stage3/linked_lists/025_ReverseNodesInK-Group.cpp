/**
 * 160. Intersection of Two Linked Lists
 * Source: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *fast = dummy, *slow = dummy;
        while (fast) {
            int i = 0;
            for (; i < k && fast; i++)
                fast = fast->next;
            if (i < k || !fast)
                break;
            ListNode *second_head = slow->next, *temp_head = second_head->next;
            second_head->next = fast->next;
            for (i = 1; i < k; i++) {
                ListNode *p = temp_head->next;
                temp_head->next = second_head;
                second_head = temp_head;
                temp_head = p;
            }
            fast = slow->next;
            slow->next = second_head;
            slow = fast;
        }
        return dummy->next;
    }
};

int main() {
    Solution s;
    std::vector<std::pair<std::vector<int>, int>> test_cases;
    test_cases.push_back({{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4});
    test_cases.push_back({{1, 2, 3, 4, 5}, 2});
    test_cases.push_back({{1, 2, 3, 4, 5}, 3});
    test_cases.push_back({{1}, 1});
    for (auto &it : test_cases) {
        std::vector<int> num = it.first;
        auto *head = new ListNode(num[0]);
        ListNode *p = head;
        for (int i = 1; i < num.size(); i++) {
            auto *temp = new ListNode(num[i]);
            p->next = temp;
            p = p->next;
        }
        ListNode *res = s.reverseKGroup(head, it.second);
        std::cout << "[";
        while (res) {
            std::cout << res->val << ",";
            res = res->next;
        }
        std::cout << "\b]\n";
        while (head) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}
