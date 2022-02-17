/**
 * offer 52. 两个链表的第一个公共节点
 * Source: https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
 */

#include <iostream>
#include <set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 时间复杂度O(M+N), 空间复杂度O(N)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode *> s;
        while (headA) {
            s.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (s.find(headB) != s.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }

    // 时间复杂度O(M+N)，空间复杂度O(1)
    ListNode *getIntersectionNodeV2(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        ListNode *tail = nullptr;  // 尾节点存储a和b的尾节点，如果两个链表不相交，可提前停止循环。
        ListNode *a = headA, *b = headB;
        while (a != b) {
            if (a->next)
                a = a->next;
            else {
                if (tail && tail != a)
                    return nullptr;
                tail = a;
                a = headB;
            }
            if (b->next)
                b = b->next;
            else {
                if (tail && tail != b)
                    return nullptr;
                tail = b;
                b = headA;
            }
        }
        return a;
    }

    // 简化V2
    // V2_1看着简单，但是如果两个链表不相交，V2_1会更耗时，特别是链表较长时，V2_1的劣势更明显
    ListNode *getIntersectionNodeV2_1(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {
    Solution s;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    ListNode *head2 = new ListNode(1);
    head2->next = head1->next;
    auto res = s.getIntersectionNodeV2_1(head1, head2);
    if (res)
        std::cout << res->val << std::endl;
    return 0;
}
