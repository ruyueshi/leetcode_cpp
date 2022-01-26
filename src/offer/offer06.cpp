/**
 * offer 06. 从尾到头打印链表
 * Source: https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 */

#include <iostream>
#include <stack>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    std::vector<int> reversePrint(ListNode* head) {
        std::vector<int> res;
        std::stack<int> s;
        while (head) {
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> a = {1,2,3,4};
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (auto i: a) {
        p->next = new ListNode(i);
        p = p->next;
    }
    auto res = s.reversePrint(head);
    for (auto i: res) {
        std::cout << i << std::endl;
    }
    return 0;
}
