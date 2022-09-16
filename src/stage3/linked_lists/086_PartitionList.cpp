/**
 * 86. Partition List
 * Source: https://leetcode.cn/problems/partition-list/
 */

#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(-1, head);
        auto p = head;
        ListNode *first_partition_end = &dummy, *second_partition_end = nullptr;
        while (p) {
            auto q = p->next;
            if (p->val < x) {
                if (second_partition_end) {
                    second_partition_end->next = p->next;
                    p->next = first_partition_end->next;
                }
                first_partition_end->next = p;
                first_partition_end = p;
            } else {
                second_partition_end = p;
            }
            p = q;
        }
        return dummy.next;
    }
};
