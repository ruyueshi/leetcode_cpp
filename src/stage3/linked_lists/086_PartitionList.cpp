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

// 在原表上操作
// 速度更快
class SolutionV1 {
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

// 记录两个表，最后合并两个表
// V2 更清晰
class SolutionV2 {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1, dummy2;
        ListNode *p1 = &dummy1, *p2 = &dummy2;
        auto p = head;
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p;
            } else {
                p2->next = p;
                p2 = p;
            }
            auto temp = p->next;
            p->next = nullptr;
            p = temp;
        }
        p1->next = dummy2.next;
        return dummy1.next;
    }
};
