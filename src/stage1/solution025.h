/**
 * 25. Reverse Nodes in k-Group
 * Source: https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
 */

#ifndef LEETCODE_CPP_SOLUTION025_H
#define LEETCODE_CPP_SOLUTION025_H

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class solution025 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *new_head = nullptr;
        ListNode *new_tail = nullptr;
        ListNode *next_head = head;
        while (next_head) {
            ListNode *reversed_head = nullptr;
            ListNode *reversed_tail = nullptr;
            bool is_last;
            // reverse current segment list
            this->reverseList(k, next_head, reversed_head, reversed_tail, is_last);

            // update new list's head and tail
            if (!new_head && !new_tail) {
                new_head = reversed_head;
                new_tail = head;
            } else {
                if (is_last) { // if current segment is the last remaining segment, reverse it again.
                    next_head = reversed_head;
                    this->reverseList(k, next_head, reversed_head, reversed_tail, is_last);
                }
                new_tail->next = reversed_head;
                new_tail = reversed_tail;
            }
        }
        return new_head;
    }

private:
    void reverseList(int k, ListNode *&next_head, ListNode *&reversed_head, ListNode *&reversed_tail, bool &is_last) {
        reversed_head = next_head;
        reversed_tail = next_head;
        ListNode *p = reversed_head->next;
        reversed_head->next = nullptr;
        is_last = false;
        for (int i = 1; i < k; i++) {
            if (!p) {
                is_last = true;
                break;
            }
            ListNode *temp = p;
            p = p->next;
            temp->next = reversed_head;
            reversed_head = temp;
        }
        // update the head pointer of next segment
        next_head = p;
    }
};

static void test_solution025() {
    std::vector<std::pair<std::vector<int>, int>> test_cases;
    test_cases.push_back({{1, 2, 3, 4, 5}, 1});
    test_cases.push_back({{1, 2, 3, 4, 5}, 2});
    test_cases.push_back({{1, 2, 3, 4, 5}, 3});
    test_cases.push_back({{1}, 1});
    solution025 s;
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
}

#endif // LEETCODE_CPP_SOLUTION025_H
